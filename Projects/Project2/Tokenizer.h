/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#ifndef TOKENIZER_H
#define TOKENIZER_H

using namespace std;

class Tokenizer {
private:
	string str;
	int current;
	int lookAhead;
	int lookBehind;
public:

	Tokenizer(std::string str) {
		this->str = str;
		this->current = 0;
		this->lookAhead = 1;
		this->lookBehind = -1;
	}
	char get(){
		return str[current];
	}

	char behind() {
		return ( ( lookBehind < 0 ) ? ( '\0' ) : ( str[lookBehind] ) );
	}

	char forward() {
		return ( ( lookAhead >= str.length( ) ) ? ( '\0' ) : ( str[lookAhead] ) );
	}

	void next() {
		if ( current < str.length( ) ) {
			current++;
			lookAhead++;
			lookBehind++;
		}
	}
};


#endif /* TOKENIZER_H */

