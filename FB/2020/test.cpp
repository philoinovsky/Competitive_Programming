#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'largestArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY samples as parameter.
 */

int largestArea(vector<vector<int>> samples) {
    int N = samples.size();
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == 0 || j == 0)
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string samples_rows_temp;
    getline(cin, samples_rows_temp);

    int samples_rows = stoi(ltrim(rtrim(samples_rows_temp)));

    string samples_columns_temp;
    getline(cin, samples_columns_temp);

    int samples_columns = stoi(ltrim(rtrim(samples_columns_temp)));

    vector<vector<int>> samples(samples_rows);

    for (int i = 0; i < samples_rows; i++) {
        samples[i].resize(samples_columns);

        string samples_row_temp_temp;
        getline(cin, samples_row_temp_temp);

        vector<string> samples_row_temp = split(rtrim(samples_row_temp_temp));

        for (int j = 0; j < samples_columns; j++) {
            int samples_row_item = stoi(samples_row_temp[j]);

            samples[i][j] = samples_row_item;
        }
    }

    int result = largestArea(samples);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
