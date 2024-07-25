class Solution:
  # finding the solution was not hard but the damn syntax was.
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        mp = {}
        for i in range(len(paths)):
            root = ""
            j = 0
            while j < len(paths[i]) and paths[i][j] != " ":
                root += paths[i][j]
                j += 1
            
            j += 1 #becausr curr we are at " "

            while j < len(paths[i]):
                file_name = ""
                while j < len(paths[i]) and paths[i][j] != "(":
                    file_name += paths[i][j]
                    j += 1

                j += 1  #because curr we are at "("
                key_name = ""
                while j < len(paths[i]) and paths[i][j] != ")":
                    key_name += paths[i][j]
                    j += 1

                if key_name not in mp:
                    mp[key_name] = []
                
                mp[key_name].append(root + "/" + file_name)
                j += 2  

        result = [group for group in mp.values() if len(group) > 1]
        return result
   


            
                







        
