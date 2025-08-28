#include <iostream>
using namespace std;

int my_strlen(const char* s){ 
    int n=0; while(s[n]) ++n; 
    return n; 
}

void my_strcpy(char* dst, const char* src){
    int i=0; 
    while( (dst[i]=src[i]) ) ++i;
}

int my_tolower(int c){
    if (c>='A' && c<='Z') 
    return c - 'A' + 'a';
    return c;
}

int my_stricmp(const char* a, const char* b){
    int i=0;
    while (a[i] && b[i]){
        int ca = my_tolower((unsigned char)a[i]);
        int cb = my_tolower((unsigned char)b[i]);
        if (ca != cb) return ca - cb;
        ++i;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}


void concat(char* a, const char* b){             
    int i = my_strlen(a), j = 0;
    while ( (a[i++] = b[j++]) ) {}            // will copy the last thingy also '\0'
}

void reverse_in_place(char* s){
    int i=0, j=my_strlen(s)-1;
    while(i<j){ 
        char t=s[i]; 
        s[i]=s[j]; 
        s[j]=t; 
        ++i; 
        --j; 
    }
}
bool is_vowel(char c){
    c = (char)my_tolower((unsigned char)c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
void delete_vowels(char* s){
    int w=0;
    for (int r=0; s[r]; ++r)
        if (!is_vowel(s[r])) s[w++] = s[r];
    s[w] = '\0';
}

void sort_strings(char a[][256], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (my_stricmp(a[j], a[j+1]) > 0){
                char tmp[256];
                my_strcpy(tmp,   a[j]);
                my_strcpy(a[j],  a[j+1]);
                my_strcpy(a[j+1],tmp);
            }
        }
    }
}

void to_lowercase(char* s){
    for (int i=0; s[i]; ++i)
        s[i] = (char)my_tolower((unsigned char)s[i]);
}

int main(){
    const int MAXL = 1000;    // max single-line length
    cout << "String Menu \n";
    while (true){
        cout << "\nChoose an option:\n"
                "1) Concatenate one string to another\n"
                "2) Reverse a string\n"
                "3) Delete all vowels from a string\n"
                "4) Sort multiple strings in alphabetical order\n"
                "5) Convert a string to lowercase\n"
                "0) Exit\n"
                "Enter choice: ";
        int ch; 
        if(!(cin >> ch)) return 0;
        cin.ignore(); // drop the newline after the number

        if (ch==0) { cout << "BaBye!\n"; break; }

        if (ch==1){
            char A[MAXL], B[MAXL];
            cout << "Enter first string: ";  cin.getline(A, MAXL);
            cout << "Enter second string: "; cin.getline(B, MAXL);
            concat(A, B);
            cout << "Concatenated: " << A << "\n";
        }
        else if (ch==2){
            char S[MAXL];
            cout << "Enter string: "; cin.getline(S, MAXL);
            reverse_in_place(S);
            cout << "Reversed: " << S << "\n";
        }
        else if (ch==3){
            char S[MAXL];
            cout << "Enter string: "; cin.getline(S, MAXL);
            delete_vowels(S);
            cout << "Without vowels: " << S << "\n";
        }
        else if (ch==4){
            int n;
            cout << "How many strings (<=100)? ";
            cin >> n; cin.ignore();
            if (n<0) n=0; if (n>100) n=100;
            char arr[100][256];
            for(int i=0;i<n;i++){
                cout << "String " << (i+1) << ": ";
                cin.getline(arr[i], 256);
            }
            sort_strings(arr, n);
            cout << "\nSorted order (case-insensitive):\n";
            for(int i=0;i<n;i++) cout << arr[i] << "\n";
        }
        else if (ch==5){
            char S[MAXL];
            cout << "Enter string: "; cin.getline(S, MAXL);
            to_lowercase(S);
            cout << "Lowercase: " << S << "\n";
        }
        else{
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
