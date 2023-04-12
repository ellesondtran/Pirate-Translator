//Elleson Tran
//Roberts
//Pirate Translator 3.0
//Makes the user's phrase into pirates language
//FINAL

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

string replace(string englishWord, string pirateReplace, string phrase){
  int placement =  -1;//to start the do while
  string newPhrase;//what we are returning
  string tempPhrase; //keeps track of the original phrase in another string 

  do{
    placement = phrase.find(englishWord, placement + 1);//finds the placement of the english word in the phrase
    if(placement != -1){//if it does find the english word in the phrase
      //phrase.substr(tempPhrase.length(), placement- tempPhrase.length() this starts off where ever the found word ends off, and goes to the placement MINUS the length because if it already found a word, it need to take that into account of the new placement
      newPhrase = newPhrase + phrase.substr(tempPhrase.length(), placement - tempPhrase.length()) + pirateReplace;
      tempPhrase = tempPhrase + phrase.substr(tempPhrase.length(), placement - tempPhrase.length()) + englishWord;//this is to use the length of the phrase as i'm adding it to avoid overlap
    }
  }while(placement != -1);
  newPhrase = newPhrase + phrase.substr(tempPhrase.length(), phrase.length());//adds anything after the last found word, because the do while stops after it finds the last one 
  //phrase.substr(tempPhrase.length(), phrase.length() goes from where ever the new phrase ends off to the ORIGINAL phrase, so anything left after the last found word
  return newPhrase;
}

string ucFirst(string word){
  string newWord;
  char firstLetter = toupper(word.at(0));//takes the first letter and capitalizes it

  newWord = newWord + firstLetter + word.substr(1);//creates a new string with the capital letter and every letter after that
  return newWord;
}

string arrr(string phrase){
  string newPhrase;
  string tempPhrase;

  string punctuation = "!.?";

  int placement = -1;

  do{
    placement = phrase.find_first_of(punctuation, placement + 1);//if it finds any puncutation in the phrase, it will produce what placement it's in
    if(placement != -1){//if it DOES find a puncutation
      int randNum = rand()%2;//creates a 50-50 chance of adding arrr
      
      if(randNum == 1){//only adds arrr if the random num is 1, instead of 0. 50-50 chance
        newPhrase = newPhrase + phrase.substr(tempPhrase.length(), (placement + 1) - tempPhrase.length()) + " Arrr!"; //same concept of replace
        tempPhrase = tempPhrase + phrase.substr(tempPhrase.length(), (placement + 1) - tempPhrase.length());
      }
    }
  }while(placement != -1);//keeps going until there is no more puncutation
  newPhrase = newPhrase + phrase.substr(tempPhrase.length(), phrase.length());
  
  return newPhrase;
}



int main() {
  srand(time(0));
  const vector<string> englishWords = {"hello", "friend", "madam", "officer", "stranger", "where", " is ", "the", "my", "your", "restaurant", "hotel", "money"};
  const vector<string> pirateWords = {"ahoy", "matey", "proud beauty", "foul blaggart", "scurvy dog", "whar", " be ", "th'", "me", "yer", "galley", "fleabag inn", "booty"};

  //phrase
  string phrase;
  cout<<endl<<"Enter your phrase: ";
  getline(cin, phrase);

  string newPhrase = phrase;//keeps the original phrase untouched

  for(int x = 0; x < englishWords.size(); x++){//goes through the vector
    string capitalEnglish = ucFirst(englishWords[x]);//makes the capital version of the english
    string capitalPirate = ucFirst(pirateWords[x]);//makes the capital verion of the pirate

    if(phrase.find(englishWords[x]) != -1){//if there is a lowercase english word in the phrase
      newPhrase = replace(englishWords[x], pirateWords[x], newPhrase);//replace is with the pirate one
    }
    if(phrase.find(capitalEnglish) != -1){//if there is a capital english word in the phrase
      newPhrase = replace(capitalEnglish, capitalPirate, newPhrase);//replace is with the capital pirate one
    }
  }

  string finalPhrase = arrr(newPhrase);
  cout<<endl<<"Pirate Version: "<<finalPhrase;
}