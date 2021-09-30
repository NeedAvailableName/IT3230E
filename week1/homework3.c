/*write a program that uses random number generation to create sentences.
The program should use four arrays of strings called article, noun, verb and preposition.
The program should create a sentence by selecting a word at random from each array in the following order: article, noun, verb, preposition, article and noun.
As each word is picked, it should be concatenated to the previuos words in an array that is large enough to hold the entire sentence.
The words should be separated by spaces. 
When the final sentence is output, it should start with a capital letter and the end with a period.
The program should generate 10 such sentences.
The article array should contain the article "the", "a", "one", "some" and "any";
the noun array should contain the nouns "boy", "girl", "dog", "town" and "car";
the verb array should contain the verbs "drove", "jumped", "ran", "walked" and "skipped";
the preposition array should contain the prepositions "to", "from", "over", "under" and "on".*/
#include<stdio.h>
#include<string.h>
#include<time.h>
int main() {
	int holder[6], x, i, j;
	char *article[]={"the", "a", "one", "some", "any"};
	char *noun[]={"boy", "girl", "dog", "town", "car"};
	char *verb[]={"drove", "jumped", "ran", "walked", "skipped"};
	char *preposition[]={"to", "from", "over", "under", "on"};
	srand(time(NULL));
	for(j=0;j<10;j++) {
		for(i=0;i<6;i++) {
			holder[i]=rand()%5;
		}
		i=0;
		printf("%s ", article[holder[i]]);
		printf("%s ", noun[holder[i]]);
		printf("%s ", verb[holder[i]]);
		printf("%s ", preposition[holder[i]]);
		printf("%s ", article[holder[i]]);
		printf("%s. ", noun[holder[i]]);
		printf("\n");
	}
	return 0;		
}
