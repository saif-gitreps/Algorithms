public class Solution
{
    private HashSet<string> visited = new HashSet<string>();
    private string ans = "";
    private int a, b, n;

    private string Rotate(string s, int x)
    {
        return s.Substring(x) + s.Substring(0, x);
    }

    private string Add(string s, int x)
    {
        char[] arr = s.ToCharArray();
        for (int i = 1; i < n; i += 2)
        {
            int val = ((arr[i] - '0') + x) % 10;
            arr[i] = (char)('0' + val);
        }
        return new string(arr);
    }

    private void Dfs(string s)
    {
        if (visited.Contains(s))
            return;

        visited.Add(s);
        if (string.Compare(s, ans) < 0)
            ans = s;

        Dfs(Add(s, a));
        Dfs(Rotate(s, b));
    }

    public string FindLexSmallestString(string s, int a, int b)
    {
        ans = s;
        this.a = a;
        this.b = b;
        n = s.Length;

        Dfs(s);
        return ans;
    }
