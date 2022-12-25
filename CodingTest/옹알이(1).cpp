#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    // 옹알이 가능한 단어들을 저장해놓는 공간 --> 이후 비교할 때 사용됨.
    vector<string> a = {"aya", "ye", "woo", "ma"};
    // word라는 변수로 babbling의 크기 만큼 반복해라.
    for(const auto& word: babbling){ // const auto라는 명령어가 생소했으나, 검색을 통해 어떤 의미인지 알아냄.
        int checkBeginIdx = 0; // 시작 주소 초기화
        bool checkFinished = false; // 끝났는지 안끝났는지 판단하는 변수 초기화

        vector<int> noProbs;

        int i;
        // 한 벡터 안에 들어있는 문자열을 알파벳 단위로 쪼개는 코드
        for(i = 0; i<word.length(); ++i){
            char wordChar = word[i];

            bool isSpable = false;

            checkFinished = false;

            for(int j=0; j<a.size(); ++j){
                if(find(noProbs.begin(), noProbs.end(), j) != noProbs.end()) continue;

                const string& spable = a[j];
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
            ++answer;
        }
    }

    return answer;
}
