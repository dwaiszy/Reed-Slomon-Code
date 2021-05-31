#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define TARGET 42

vector<string> p_operators; // store all operators permutation

void permute(const char str[], string prefix, const int n, const int length)
{
    if (length == 0)
    {
        p_operators.emplace_back(prefix);
    } // Base case, prefix is the result of permutation
    else
    {
        // use recursion to calculate permutation of these operators
        // these operators can be repeated
        for (int i = 0; i < n; i++)
            permute(str, prefix + str[i], n, length - 1);
    }

}

int calculate(char opr, int val1, int val2)
{
    switch (opr)
    {
    case '*':
        return val1 * val2;
        break;
    case '+':
        return val1 + val2;
        break;
    case '-':
        return val1 - val2;
        break;
    default:
        break;
    }
}

int main() {
    string line;
    string prefix = "";

    int index = 0;
    char operators[] = { '*', '+', '-' };
    permute(operators, prefix, 3, 4);

    int cards[5];
    int arr[120][5];

    int count = 0;

    string number;

    // Retrieve numbers from input
    while (getline(cin, line)) {
        int size = line.size();
        for (int i = 0; i <= size; i++)
        {
            if (line[i] != ' ' and line[i] != NULL)
            {
                count++;
                number += line[i];
            }
            else
            {
                if (!number.empty())
                {
                    int n = stoi(number);
                    cards[index] = n;
                }
                index++;
                count = 0;
                number.clear();
            }
        }
    }

    // Calculate permutation of the cards
    sort(cards, cards + 5);
    index = 0;

    do {
        copy(std::begin(cards), std::end(cards), std::begin(arr[index]));
        index++;
    } while (next_permutation(cards, cards + 5));

    int size = p_operators.size();

    // Calculate all possible results from all permutations
    // return when result equals to 42
    for (int i = 0; i < 120; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int result = arr[i][0];

            for (int k = 0; k < 4; k++)
                result = calculate(p_operators[j][k], result, arr[i][k + 1]);

            if (result == TARGET)
            {
                cout << "YES";
                return 0;
            }

        }
    }
    cout << "NO";
}

