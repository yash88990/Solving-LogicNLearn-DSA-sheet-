class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int original_a = a;
        int original_b = b;
        
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        int hcf = a;
        int lcm = (original_a  * original_b) / hcf;
        
        vector<int> ans;
        ans.push_back(lcm);
        ans.push_back(hcf);

        return ans;
    }
};
