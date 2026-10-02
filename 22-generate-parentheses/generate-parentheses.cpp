class Solution {
public:

    void generatePara(string a,vector<string>&res ,int n,int countopen,int countclose){
        if(a.length()==2*n){
            res.push_back(a);
            return;
        }
        if(countopen<n){
        generatePara(a+"(",res,n,countopen+1,countclose);}
        if(countclose<countopen){
         generatePara(a+")",res,n,countopen,countclose+1);}
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string a = "";
        int countopen =0;
        int countclose = 0;
        generatePara(a,res,n,countopen,countclose);
        return res;
    }
};