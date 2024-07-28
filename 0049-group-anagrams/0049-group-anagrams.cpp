
class Solution {
public:
    string generateHashKey(const string& s) {
        string sortedString = s;
        sort(sortedString.begin(), sortedString.end());
        return sortedString;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable;

        // Group strings by their sorted string key
        for (const string& s : strs) {
            string key = generateHashKey(s);
            hashTable[key].push_back(s);
        }

        // Extract groups of anagrams from hash table
        vector<vector<string>> groupedAnagrams;
        for (const auto& entry : hashTable) {
            groupedAnagrams.push_back(entry.second);
        }

        return groupedAnagrams;
    }
};