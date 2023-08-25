/*
정렬해서 동일한 애들끼리 index모으기?
문자열도 결국 char의 배열이니까 문자열마다 정렬하고 벡터에 넣어서 또 정렬하면 같은 문자열끼리 모이니까
해당 애들의 index를 모아서 answer에 넣기
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<pair<string,int>> v;
        vector<string> tmp = strs;
        for(int i=0; i<tmp.size(); i++){
            sort(tmp[i].begin(),tmp[i].end());
            v.push_back({tmp[i],i});
        }
        sort(v.begin(), v.end());
        int index =0;
        while(index<v.size()){
            vector<string> group;
            group.push_back(strs[v[index].second]);
            while(index<v.size()-1 && v[index].first == v[index+1].first){
                group.push_back(strs[v[index+1].second]);
                index++;
            }
            answer.push_back(group);
            index++;
        }
        return answer;
    }
};