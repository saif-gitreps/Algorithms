class Solution {
public:
  /*
  explanation here, so its more like a simulation based on imagination type.
  so it seems that the mirror will extend until and unless a receptor is hit.
  so for that if it does not hit a receptor then it extends imaginary , now the amount
  of reflection is the amount of bounces it did before it hit the receptor.
  what is the use of the loop?
  well first we reduce with /2 until and unless we get either of them as odd.
  now after reduction , if suppose a mirror did not hit any of the receptor after two inccident, then
  an extension is formed and finally it hits 0th receptor (imaginary).
  now if it only bounces twice, then it will always reach the 2nd .
  if it never bounces the know it directly hits 1st always.
  the rest of the code is self explanatory .
  */
    int mirrorReflection(int p, int q) {
    int exten = q; int reflection = p;
    while(exten%2==0 && reflection%2==0){
        exten /= 2;
        reflection /= 2;
    } 
    if(exten%2==0 && reflection%2!=0){
        return 0;
    }
    if(exten%2!=0 && reflection%2==0){
        return 2;
    }
    if(exten%2!=0 && reflection%2!=0){
        return 1;
    }
    return -1;
}
};
