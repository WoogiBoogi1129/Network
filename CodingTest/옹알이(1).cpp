#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int spWordCnt = 0;

    vector<string> vSpables; // speakable
    vSpables.push_back("aya");
    vSpables.push_back("ye");
    vSpables.push_back("woo");
    vSpables.push_back("ma");

    for(const auto& word: babbling){
        int checkBeginIdx = 0;
        bool checkFinished = false;

        vector<int> noProbs;

        int i;
        for(i = 0; i<word.length(); ++i){
            char wordChar = word[i];

            bool isSpable = false;

            checkFinished = false;

            for(int j=0; j<vSpables.size(); ++j){
                if(find(noProbs.begin(), noProbs.end(), j) != noProbs.end()) continue;

                const string& spable = vSpables[j];
                int spableCharIdx = i - checkBeginIdx;

                if(wordChar == spable[spableCharIdx]){
                    isSpable = true;

                    if(spableCharIdx == spable.length() - 1){
                        noProbs.clear();
                        checkBeginIdx = i + 1;
                        checkFinished = true;
                        break;
                    }
                } else{
                    noProbs.push_back(j);
                }
            }

            if(!isSpable) break;
        }

        if(i == word.length() && checkFinished){
            ++spWordCnt;
        }
    }

    return spWordCnt;
}
