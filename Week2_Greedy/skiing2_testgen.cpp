#include <bits/stdc++.h>
#include <sys/wait.h>
using namespace std;
using ll = long long;

// Custom class to handle interactive testing
class TestEnvironment
{
private:
    vector<ll> heights;
    ll  n;
    ll  summit;
    ll  queries_used = 0;
    const ll  MAX_QUERIES = 200;

public:
    TestEnvironment(ll  size, ll  summit_pos = -1)
    {
        n = size;
        heights.resize(n);

        // Generate mountain with a summit at summit_pos or random position
        if (summit_pos == -1)
        {
            summit = rand() % n;
        }
        else
        {
            summit = summit_pos;
        }

        // Generate heights - decreasing from summit in both directions
        for (ll  i = 0; i < n; i++)
        {
            //heights[i] = 10;
            heights[i] = n - abs(i - summit);
        }
    }

    // Print mountain details
    // void print_mountain()
    // {
    //     cout << "Mountain size: " << n << endl;
    //     cout << "Summit at position: " << summit << endl;
    //     cout << "Heights: ";
    //     for (ll  i = 0; i < n; i++)
    //     {
    //         cout << heights[i] << " ";
    //     }
    //     cout << endl;
    // }

    // Handle a query: returns 1 if height[a] < height[b], 0 otherwise
    ll  query(ll  a, ll  b)
    {
        queries_used++;
        if (queries_used > MAX_QUERIES)
        {
            cout << "ERROR: Too many queries used!" << endl;
            exit(1);
        }

        if (a < 0 || a >= n || b < 0 || b >= n)
        {
            cout << "ERROR: Query position out of bounds!" << endl;
            exit(1);
        }

        return heights[a] < heights[b] ? 1 : 0;
    }

    // Check if the found summit is correct
    bool check_result(ll  found_summit)
    {
        return found_summit == summit;
    }

    // Get the total queries used
    ll  get_queries_used()
    {
        return queries_used;
    }

    ll  get_n()
    {
        return n;
    }

    // Run the skiing2 program with this test case
    void run_test()
    {
        // Fork and exec the skiing2 program
        int input_pipe[2], output_pipe[2];
        if (pipe(input_pipe) == -1 || pipe(output_pipe) == -1)
        {
            perror("pipe");
            exit(1);
        }

        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }

        if (pid == 0)
        { // Child process - exec skiing2
            // Redirect stdin/stdout
            dup2(input_pipe[0], STDIN_FILENO);
            dup2(output_pipe[1], STDOUT_FILENO);

            // Close unused pipe ends
            close(input_pipe[0]);
            close(input_pipe[1]);
            close(output_pipe[0]);
            close(output_pipe[1]);

            // Execute skiing2
            execlp("./skiing2", "./skiing2", NULL);
            perror("execlp");
            exit(1);
        }
        else
        { // Parent process - handle interaction
            // Close unused pipe ends
            close(input_pipe[0]);
            close(output_pipe[1]);

            // First send the mountain size
            char buffer[1024];
            sprintf(buffer, "%d\n", n);
            write(input_pipe[1], buffer, strlen(buffer));

            bool finished = false;
            int found_summit = -1;

            // Interactive loop
            while (!finished && queries_used < MAX_QUERIES)
            {
                memset(buffer, 0, sizeof(buffer));
                read(output_pipe[0], buffer, sizeof(buffer) - 1);

                string cmd(buffer);
                if (cmd.empty())
                    continue;

                if (cmd[0] == '?')
                { // Query
                    int a, b;
                    sscanf(buffer, "? %d %d", &a, &b);
                    int result = query(a, b);
                    sprintf(buffer, "%d\n", result);
                    write(input_pipe[1], buffer, strlen(buffer));
                }
                else if (cmd[0] == '!')
                { // Result
                    sscanf(buffer, "! %d", &found_summit);
                    finished = true;
                }
            }

            // Close remaining pipe ends
            close(input_pipe[1]);
            close(output_pipe[0]);

            // Wait for child to finish
            int status;
            waitpid(pid, &status, 0);

            // Output result
            if (finished)
            {
                cout << "Program found summit at position " << found_summit << endl;
                cout << "Correct summit is at position " << summit << endl;
                cout << "Result: " << (check_result(found_summit) ? "CORRECT" : "WRONG") << endl;
            }
            else
            {
                cout << "Program did not provide a result!" << endl;
            }
            cout << "Queries used: " << queries_used << "/" << MAX_QUERIES << endl;
        }
    }
};

// Manual test function - manually interact with the skiing2 program
void manual_test(ll  n, ll  summit_pos)
{
    vector<ll > heights(n);

    // Generate heights - decreasing from summit in both directions
    for (ll  i = 0; i < n; i++)
    {
        heights[i] = 100 - abs(i - summit_pos);
    }

    // Print mountain details
    // cout << "Mountain size: " << n << endl;
    // cout << "Summit at position: " << summit_pos << endl;
    // cout << "Heights: ";
    // for (ll  i = 0; i < n; i++)
    // {
    //     cout << heights[i] << " ";
    // }
    // cout << endl;

    // Create input file for manual testing
    ofstream input_file("skiing2.input");
    input_file << n << endl;

    cout << "Now you can run: ./skiing2 < skiing2.input" << endl;
    cout << "When the program asks '? a b', check if height[a] < height[b]:" << endl;
    cout << "- If height[a] < height[b], enter 1" << endl;
    cout << "- If height[a] >= height[b], enter 0" << endl;

    input_file.close();
}

int main(int argc, char *argv[])
{
    srand(time(nullptr));

    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <test_type> [args]" << endl;
        cout << "Test types:" << endl;
        cout << "  1 - Random test" << endl;
        cout << "  2 - Edge case: Summit at start" << endl;
        cout << "  3 - Edge case: Summit at end" << endl;
        cout << "  4 - Edge case: Mountain with plateau" << endl;
        cout << "  5 - Manual test with size N and summit pos P" << endl;
        return 1;
    }

    int test_type = atoi(argv[1]);

    switch (test_type)
    {
    case 1:
    {
        int n = (argc > 2) ? atoi(argv[2]) : 10;
        TestEnvironment env(n);
        //env.print_mountain();
        env.run_test();
        break;
    }
    case 2:
    {
        int n = (argc > 2) ? atoi(argv[2]) : 10;
        TestEnvironment env(n, 0); // Summit at start
        //env.print_mountain();
        env.run_test();
        break;
    }
    case 3:
    {
        int n = (argc > 2) ? atoi(argv[2]) : 10;
        TestEnvironment env(n, n - 1); // Summit at end
        //env.print_mountain();
        env.run_test();
        break;
    }
    case 4:
    {
        // Not implemented in this example
        cout << "Plateau test not implemented yet" << endl;
        break;
    }
    case 5:
    {
        if (argc < 4)
        {
            cout << "For manual test, provide: " << argv[0] << " 5 <size> <summit_pos>" << endl;
            return 1;
        }
        ll  n = atoi(argv[2]);
        ll  summit_pos = atoi(argv[3]);
        manual_test(n, summit_pos);
        break;
    }
    default:
        cout << "Unknown test type" << endl;
        return 1;
    }

    return 0;
}