#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

void processText(const string &inputLine)
{
    list<char> text;
    list<char>::iterator cursor(text.begin());

    for (size_t i = 0; i < inputLine.size(); ++i)
	{
        if (inputLine[i] == '[')
            cursor = text.begin();
        else if (inputLine[i] == ']')
            cursor = text.end();
        else
            text.insert(cursor, inputLine[i]);
    }

    copy(text.begin(), text.end(), ostream_iterator<char>(cout, ""));
    cout << endl;
}

int main(void)
{
    string line;
	
    while (getline(cin, line))
        processText(line);

    return (0);
}
