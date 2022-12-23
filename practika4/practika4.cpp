#include <iostream>
#include <string>
#include <fstream>



using namespace std;
string Deletespace(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] == ' ') && (s[i + 1] == ' ')) {
            while (s[i + 1] == ' ')
                s.erase(i + 1, 1);
            i++;
        }
    }
    return s;
}
void linearfnd(string s, string l)
{
    int p = 0;
    if (s.find(l) == string::npos)
    {
        cout << "Dont have this(" << endl;
    }
    else
    {
        while ((p = s.find(l, p)) != string::npos)
        {
            cout << p << " ";
            p += l.length();
        }
    }
    cout << endl;
}
string DeleteZn(string s) {
    for (int i = 0; i < s.length(); i++) {
        {
            if ((s[i] == '.') && (s[i + 1] == '.')) {
                while (s[i + 1] == '.')
                    s.erase(i + 1, 1);
                i++;
            }
            if ((s[i] == ',') && (s[i + 1] == ',')) {
                while (s[i + 1] == ',')
                    s.erase(i + 1, 1);
                i++;
            }
            if ((s[i] == ';') && (s[i + 1] == ';')) {
                while (s[i + 1] == ';')
                    s.erase(i + 1, 1);
                i++;
            }
            if ((s[i] == ':') && (s[i + 1] == ':')) {
                while (s[i + 1] == ':')
                    s.erase(i + 1, 1);
                i++;
            }
            if ((s[i] == '?') && (s[i + 1] == '?')) {
                while (s[i + 1] == '?')
                    s.erase(i + 1, 1);
                i++;
            }
            if ((s[i] == '!') && (s[i + 1] == '!')) {
                while (s[i + 1] == '!')
                    s.erase(i + 1, 1);
                i++;
            }
        }
    }
    return s;
}
string regEdit(string s)
{
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i - 1] == ' ')
        {
            i++;
        }
        s[i] = tolower(s[i]);
    }
    return s;
}
void Double(string s)
{
    int a = 0;
    bool ds = false;
    for (int i = 1; i < s.length(); i++)
    {
        if (tolower(s[i]) == tolower(s[i + 1]))
        {
            ds = true;
        }
        if (s[i] == ' ')
        {
            if (ds == true) {
                for (int j = a; j <= i - 1; j++)
                {
                    if (s[j] != '.' && s[j] != ',' && s[j] != '!' && s[j] != '?' && s[j] != ';' && s[j] != ':')
                    {
                        cout << s[j];
                    }
                }
                cout << " ";
                a = i + 1;
                ds = false;
            }
            else
            {
                a = i + 1;
                ds = false;
            }
        }
    }
}
string PropisBuk(string s)
{
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i - 1] == ' ')
        {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}


int main() {
    string s;
    while (true) {
        string task;
        cout << "Select task:\n"
            "1. Enter text\n"
            "2. Fixed text\n"
            "3. Identical letters\n"
            "4. Uppercase letter\n"
            "5. Substrings\n";

        getline(cin, task);
        cout << '\n' << '\n';
        if (task == "1") {
            string task2;
            cout << "Select way:\n"
                "1. Keyboard\n"
                "2. File\n";
            getline(cin, task2);
            if (task2 == "1") {


                cout << "Enter text:" << '\n';
                getline(cin, s);
                s = s + " ";
                cout << '\n';
                cout << "Your text:" << '\n';
                cout << s << endl;
                cout << '\n';
            }
            if (task2 == "2") {
                ifstream file("C://123.txt");
                char a;
                while (!file.eof())
                {
                    file.get(a);
                    s.push_back(a);
                }
                cout << "Your text:" << '\n';
                cout << s << '\n';
            }
        }
        if (task == "2") {
            s = DeleteZn(s);
            s = Deletespace(s);
            s = regEdit(s);
            s = DeleteZn(s);
            cout << "Corect text:" << '\n';
            cout << s << endl;
            cout << '\n';
        }
        if (task == "3") {
            cout << "Words with the same letters: ";
            Double(s);
            cout << endl;
        }
        if (task == "4") {
            cout << "Text, in which all the words with a capital letter:" << '\n';
            s = PropisBuk(s);
            cout << s << endl;
        }
        if (task == "5") {
            string l;
            cout << "Enter word: ";
            cin >> l;
            linearfnd(s, l);
        }
    }
}

