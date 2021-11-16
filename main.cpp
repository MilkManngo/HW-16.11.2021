
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int main()
{
   float arr[20];

   for (int i=0; i<20; i++) {
       arr [i] = (rand() % 900 + 100)*0.1;
   }

   for (int i=0; i<20; i++) {
       cout << "arr [" << i << "] = " << arr[i] << endl;
   }




      for(int k=1; k<20; k++)
      {
          float temp = arr[k];
          int j= k-1;
          while(j>=0 && temp <= arr[j])
          {
              arr[j+1] = arr[j];
              j = j-1;
          }
          arr[j+1] = temp;
      }
      cout<<"\nSorted list is \n";
      for(int i=0;i<20;i++)
      {
          cout <<arr[i]<<"\t"<<endl;
      }
    return 0;
}

=================================================================================================================================================================================

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include<string>

using namespace std;

int main()
{

      int arra[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
      float number;
      cout << "Please enter a float value: "<< endl;
      cin >> number;
      for (int i=0; i<19;i++) {
          if ((arra[i]-0.5<=number) && (number<arra[i+1]-0.5)) {
              cout << "Number closest to chosen in an array of numbers from 1 to 20 is: " << arra[i] << endl;
              break;

          }
          else if (number>arra[19]) {
              cout << "Number closest to chosen in array is: 20" << endl;
              break;
          }
          else if (number<arra[0]){
               cout << "Number closest to chosen in array is: 1" << endl;
               break;
          }
          else {continue;}
      }



    return 0;
} 

=================================================================================================================================================================================

#include<iostream>
#include <string>

using namespace std;

string wordReverse(string str)
{
    int i = str.length() - 1;
    int start, end = i + 1;
    string result = "";

    while(i >= 0)
    {
        if(str[i] == ' ')
        {
            start = i + 1;
            while(start != end)
                result += str[start++];

            result += ' ';

            end = i;
        }
        i--;
    }
    start = 0;
    while(start != end)
        result += str[start++];

    return result;
}

// Driver code
int main()
{
    string str, word;
    cout << "Enter a sentence below" << endl;
    getline (cin, str);

    cout << "The sentence in reverse is: " << endl;
    cout << wordReverse(str) << endl;

    cout << "Now enter a word to look for" << endl;
    cin >> word;



    return 0;
}

=================================================================================================================================================================================

#include <iostream>
using namespace std;
void printIndex(string str, string s)
{

    bool flag = false;
    for (int i = 0; i < str.length(); i++) {
        if (str.substr(i, s.length()) == s) {
            cout << i << " ";
            flag = true;
        }
    }

    if (flag == false)
        cout << "NONE";
}
int main()
{
    string str1;
    cout << "Enter a sentence below" << endl;
    getline (cin, str1);
    string str2;
    cout << "Now enter a word to look for indices of occurences in that sentence: " << endl;
    getline (cin, str2);
    printIndex(str1, str2);
    return 0;
} */

=================================================================================================================================================================================    
    
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replaceWord(const char* s, const char* oldW,
                  const char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);


    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;


            i += oldWlen - 1;
        }
    }


    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s) {

        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}
using namespace std;
int main()
{
    char str[] = "I have to be honest. I was a little bit nervous the first time I had an MRI scan";
    cout << "The example sentence is: \n" << str << endl;
    cout << "Choose a word to be replaced: " << endl;
    char word[15];
    cin >> word;
    char replacement[15];
    cout << "Now choose a word to replace it with: " << endl;
    cin >> replacement;

    char* result = NULL;


    printf("Old string: %s\n", str);

    result = replaceWord(str, word, replacement);
    printf("New String: %s\n", result);

    free(result);
    return 0;
}

