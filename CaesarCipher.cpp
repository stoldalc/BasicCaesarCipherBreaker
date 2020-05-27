#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;

/**
 * Letter struct
 * containts two ints 
 * -int letter containts the alphabetPos of the letter
 * -int frew containts the frew of the letter in the cipher text
 */
struct letter{
        int letter;
        int freq;
    };

/**
 * A B C D E F G H I J K L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
 * 0 1 2 3 4 5 6 7 8 9 0 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
 * The most popular letters in order are 
 * E(4) T(19) A(0) O(14) I(I) N(13)
 */


/**
 * codeBreak
 * takes in parameters
 *  encryptied string
 * then outputs results for the string
 */
void codeBreak(string encryptiedStr);

/**
 * Encrypt string
 * Takes two parameters
 *  First is the string the user wants to encrypt 
 *  Second is the shift key the user wants to use
 */ 
void Encrypt(string m, int shift); 
 
/**
 * Decrypt string
 * Takes two parameters
 *  First is the encrypted string
 *  Second is the shift key
 */
void Decrypt(string m, int shift);


/**
 * Letter count 
 * returns a vector of ints size 25 that contains the number of times
 * Each Letter occurs
 */
vector<letter> LetterCount(string str);

/**
 * mosFreq
 * returns a vector of ints size 6 that contains the letters(by #pos in alphabet)
 * that are the most popular
 */
vector<int> mosFreq(vector<letter> v);

/** 
 * mosFreqHelper
 * recurisive helper func for mosFreq the take params of
 *  Current top 6 most freq letters
 *  Index of the current top 6 most freq letter being observed
 *  The current letter being observed 
 * It then checks if the current obs letters freq is greater then the current 
 * obs top 6 letter and swaps if it is 
 * if not the letter is in the right spot
 */ 
vector<letter> mosFreqHelper(vector<letter> currentTop6, int top6Index);

/**
 * intAlph2Str(int var)
 * takes in a int and returns a char
 */ 
char intAlph2Str(int var);

/**
 * intAlph2Str(int var)
 * takes in a int and returns a char
 */ 
char intAlph2StrUPPER(int var);



/**
 * letterSwap
 * swaps the content of two of the letter containers
 */
void letterSwap(letter x, letter y);

/**
 * PrintVector
 * prints the int vector passed to it
 */
void PrintVector(vector<int> v);
void PrintVector(vector<string> v);  


/**
 * printLetterVec
 * Prints a vector of letter objects
 */
void printLetterVec(vector<letter> l);


int main()
{
    
    int userSelection;
    
    while(userSelection != 4){
        cout << "********* Menu *********" << endl;
        cout << "1. Break a message" << endl;
        cout << "2. Encrypt a mesage" << endl;
        cout << "3. Decrypt a message"<< endl;
        cout << "4. Exit" << endl;
        cin >> userSelection;
        switch(userSelection){
            case 1 :{
                cout << "Please enter the string you want to break" << endl;
            string m1;
            cin >> m1;
            codeBreak(m1);
            break;
            }
            
            
            case 2 :{
              cout << "Please enter the string you want to encrypt" << endl;
            string m2;
            cin >> m2;
            cout << "Please enter the shift key you would like to use" << endl;
            int shift;
            cin >> shift;
            Encrypt(m2,shift);  
            break;
            }
            case 3 :{
                cout << "Please enter the message to be decrypted" << endl;
            string m3;
            cin >> m3;
            cout << "Please enter the shift key" << endl;
            int shift3;
            cin >> shift3;
            Decrypt(m3,shift3);
            }
            
            
            
            break;
            
            case 4:
            
            break;
        }
        
    }
    
    //string str = "test";
    //Current encryption key is 5
    //string strEncrypted = "uryyb zl anzr vf puevfgvna";
    //codeBreak(strEncrypted);

    
    return 0;
}
void codeBreak(string encryptiedStr){
    
    vector<letter> resultsL;
    vector<int> resultsI;
    char mostFreqLettersInEnglish[6] = {'e','t','a','o','i','n'};
    //Returns a list vector of letter objs that contain the letter and its freq
    resultsL = LetterCount(encryptiedStr);
    //Returns a int vector of what letters are likely e
    resultsI = mosFreq(resultsL);
    
    //PrintVector(resultsI);

    vector<string> decipheredStrs;
    int shiftKeyStorage[6];
    
    for(int i = 0; i < resultsI.size(); i++){
        
        decipheredStrs.push_back("");
        //int shiftKey = resultsI[i] - (mostFreqLettersInEnglish[i]-97);
        int shiftKey = resultsI[i] - ('e'-97);
        shiftKeyStorage[i] = shiftKey;
        //cout << "Assuming " << intAlph2Str(resultsI[i]) <<  " represnts e the shift key is " << shiftKey << endl;
        
        
        
        for(int j = 0; j < encryptiedStr.size();j++){
            if(encryptiedStr[j] != 32){
                int buffer = ((encryptiedStr[j]-97)-shiftKey)%26;
            if(buffer < 0){
                buffer = 26+buffer;
            }
            
            //cout << int(encryptiedStr[j]-97) << " - " << shiftKey << " mod 26 = " << buffer << endl;
            
            decipheredStrs[i]+=intAlph2Str(buffer);
            }
            else{
                decipheredStrs[i] += ' ';
            }
            
        }
        //cout << endl << endl;
    }
    for(int i = 0; i < decipheredStrs.size();i++){
        cout << i << ". Deciphered message is \" " << decipheredStrs[i] << "\" with shift key " << shiftKeyStorage[i] <<  endl;
    }
    //PrintVector(decipheredStrs);
    
}

void Encrypt(string m, int shift){
    string result = "";
    
    if((m[0] >= 97)&&(m[0] < 123)){
            cout << "Test1" << endl;
        for(int i = 0; i < m.size();i++){
            cout << "Loop" << endl;
        int buffer = ((m[i]-97)+shift)%26;
        result += intAlph2Str(buffer);
        }
    }
    else if((m[0] >= 65)&&(m[0] < 91)){
        cout << "Test2" << endl;
       for(int i = 0; i < m.size();i++){
           cout << "Loop" << endl;
        int buffer = ((m[i]-65)+shift)%26;
        result += intAlph2StrUPPER(buffer);
        } 
    }
    else{
        cout << "Invalid string" << endl;
    }
    
    cout << "Encrypted message is: " << result << endl;
}

void Decrypt(string m, int shift){
    string result;
    
    if((m[0] >= 97)&&(m[0] < 123)){ 
        for(int i = 0; i < m.size(); i++){
            result += intAlph2Str((m[i]-97)-shift);
        }
    }
    else if((m[0] >= 65)&&(m[0] < 91)){
        for(int i = 0; i < m.size(); i++){
            result += intAlph2StrUPPER((m[i]-65)-shift);
        }
    }
    else{
        cout << "Invalid string" << endl;
    }
    
    cout << result << endl;
    
}

vector<letter> LetterCount(string str){
    
    vector<letter> results(26);
    
    //cout << str.size() << endl;
    for (int i = 0; i < str.size();i++) {
        //cout << i << " " << str[i] << endl;
        
        //If the ascII value of the char is between 97 and 123
        //then it is upercase 
        if((str[i] >= 97)&&(str[i] < 123)){
            
            int alphabetPos;
            
            //Subtracting 97 puts a at 0
            alphabetPos = str[i] - 97;
            
            results[alphabetPos].letter = alphabetPos;
            results[alphabetPos].freq++;
            
            //cout << "Current letter is: " << str[i] << " " << results[alphabetPos].letter << " and has occured " 
            //<< results[alphabetPos].freq << endl;
        }
        //If the ascII value of the char is between 65 and 91
        //then it is upercase 
        else if((str[i] >= 65)&&(str[i] < 91)){
            
            int alphabetPos;
            
            //Subtracting 65 puts A at 0
            alphabetPos = str[i] - 65;
            
            results[alphabetPos].letter = alphabetPos;
            results[alphabetPos].freq++;
            
            //cout << "Current letter is: " << str[i] << " " << results[alphabetPos].letter << " and has occured " 
            //<< results[alphabetPos].freq << endl;
        }
        //If the ascII val of the char is not in either of those ranges
        //it is a non letter char
        else{
            //cout << "INVALID STRING" << endl;
        }
    }
    
    return results;
}




vector<int> mosFreq(vector<letter> v){
    
    
    
    /**
     * so if the letter X is the most freq X is probs e
     * if we find a new most popular letter Y it is probs e
     * and X is probs t
     * ....
     */ 
     
     /**
      * (DNS)
      * Maybe a for loop that calls a recursive function to check if
      * the freq of the current letter is greater then any of the current 
      * top freqs 
      * 
      * I probably need a vec<letters> to hold the results
      * 
      * Could be simplier solution then this 
      * 
      * 
      */
      
      /**
       *If a letter X is more frequent then the current 6th most freq letter
       *make X the most freq letter
       * 
       * If X is more frequent then the currrent 5th most freq letter
       * 
       */
      

    vector<letter> resultsL(6);
    
    for(int i = 0; i < resultsL.size(); i++){
        resultsL[i].letter = 0;
        resultsL[i].freq = 0;
    }
    

     for(int i = 0; i < 26;i++){
        if(resultsL[5].freq < v[i].freq){
            //cout << "Current freq is greater then then the 6th most freq num" << endl;
            
            resultsL[5].letter = v[i].letter;
            resultsL[5].freq = v[i].freq;
            
            //cout << "Results[5] letter and freq are: " << resultsL[5].letter << " " << resultsL[5].freq << endl;
            
            resultsL = mosFreqHelper(resultsL,5);
        }
     }
     //cout << "We arent out of the for loop are we" << endl;
     
     vector<int> resultsI(6);
     for(int i = 0; i < resultsL.size(); i++){
         resultsI[i] = resultsL[i].letter;
     }
     return resultsI;
}



vector<letter> mosFreqHelper(vector<letter> currentTop6, int top6Index){
    //printLetterVec(currentTop6);
    //cout << endl;
    //cout << "Inside recuresive func" << endl;
    if((top6Index > currentTop6.size()-1)||(top6Index-1 < 0)){
        //cout << "Returning out of recursive func due to base case" << endl;
        return currentTop6;
    }
    //cout << "Is it seging because of my couts?" << endl;
    //cout << "currentTop6 at top6Index is: " << "Letter-" << currentTop6[top6Index].letter << " Freq-" << currentTop6[top6Index].freq << " with index" << top6Index << endl;
    //cout << "currentTop6 at top6Index-1 is: " << "Letter-" << currentTop6[top6Index-1].letter << " Freq-" << currentTop6[top6Index-1].freq << " with index" << top6Index-1  << endl;
    if(currentTop6[top6Index].freq > currentTop6[top6Index-1].freq){
        //cout << "Inside recusion if statment" << endl;
        
        
        letter buffer;
        //cout << "Test 1"<< endl;
        buffer = currentTop6[top6Index];
        //cout << "Test 2"<< endl;
        currentTop6[top6Index] = currentTop6[top6Index-1];
        //cout << "Test 3"<< endl;
        currentTop6[top6Index-1] = buffer;
        //cout << "Test 4" << endl;
        
        
        //letterSwap(currentTop6[top6Index],currentTop6[top6Index-1]);
        
        if(top6Index-1 < 0){
            return currentTop6;
        }
        //cout << "recursive call with index: " << top6Index-1 << endl;
        currentTop6 = mosFreqHelper(currentTop6,top6Index-1);
        //cout << "returned out of rec call" << endl;
    }
    
    //cout << "Returning due to no statment" << endl;
    //printLetterVec(currentTop6);
    return currentTop6;
    
}




void letterSwap(letter x, letter y){
    int freqBuffer = x.freq;
    int letterBuffer = x.letter;
    
    x.freq = y.freq;
    x.letter = y.letter;
    
    y.freq = freqBuffer;
    y.letter = letterBuffer;
}


void printLetterVec(vector<letter> l){
    for(int i = 0; i < l.size();i++){
        cout << i << ". Letter: " << l[i].letter <<  " Freq: " << l[i].freq << endl; 
    }
}


void PrintVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << i << ". " << v[i] << endl;
    }
}
void PrintVector(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << i << ". " << v[i] << endl;
    }
}

char intAlph2Str(int var){
    if((var > -1)&&(var <26)){
        return var+97;
    }
}

char intAlph2StrUPPER(int var){
    if((var > -1)&&(var <26)){
        return var+65;
    }
}












