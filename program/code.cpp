#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int WAITTIME = 50;
mt19937 gen (
    random_device{}() ^ 
    (chrono::high_resolution_clock::now().time_since_epoch().count() / 1000000LL)
);
int randint(int l, int r) {
    uniform_int_distribution<int> rint_(l, r);
    return rint_(gen);
}
template<typename T>
T random_choice(vector<T> vec) {
    return vec[randint(0, vec.size() - 1)];
}
class Pianist {
private:
	vector<string> sentences;
public:
	Pianist(string filename) {
		ifstream fin(filename);
		string tmp;
        while(getline(fin, tmp)) {
            sentences.push_back(tmp);
        }
	}
	void answer(string input) {
		speak(random_choice(sentences));
	}
	void speak(string s) {
		cout << s << endl;
		Sleep(static_cast<int>(s.length()) * WAITTIME);
	}
	~Pianist() {
		speak("ƒ„ ≤√¥“‚Àº∞°£ø"); 
		Sleep(1000);
	}
};
int main(){
	Pianist PYN("sentences.pyn");
	string input;
	while(true) {
		cout << ">>> ";
		getline(cin, input);
		if(input == "see you") {
			break;
		} else {
			PYN.answer(input);
		}
	}
	return 0;
}
