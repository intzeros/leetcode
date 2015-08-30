class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> vec;
        int i = 0, num = 0;
        while(i < input.size() && input[i] <= '9' && input[i] >= '0'){
            num *= 10;
            num += input[i] - '0';
            i++;
        }
        if(i == input.size()){
            vec.push_back(num);
            return vec;
        }

        for(int r = 0; r < input.size(); r++){
            if(input[r] == '-' || input[r] == '+' || input[r] == '*'){
                vector<int> vec1 = diffWaysToCompute(input.substr(0, r));
                vector<int> vec2 = diffWaysToCompute(input.substr(r+1, input.size()));
                for(int i = 0; i < vec1.size(); i++){
                    for(int j = 0; j < vec2.size(); j++){
                        int rst;
                        if(input[r] == '-') rst = vec1[i] - vec2[j];
                        else if(input[r] == '+') rst = vec1[i] + vec2[j];
                        else if(input[r] == '*') rst = vec1[i] * vec2[j];
                        vec.push_back(rst);
                    }
                }
            }
        }
        return vec;
    }
};
