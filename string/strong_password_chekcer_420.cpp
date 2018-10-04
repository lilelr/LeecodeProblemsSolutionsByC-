//https://leetcode.com/problems/strong-password-checker/discuss/151333/Easy-O(n)-solution
//Premium
//        New Playground
//4
//lilelr
//
//420. Strong Password Checker
//        DescriptionHintsSubmissionsDiscussSolution
//
//Easy O(n) solution
//        Easy O(n) solution
//293
//VIEWS
//2
//Last Edit: August 30, 2018 5:58 AM
//
//        meng789987
//meng789987
//163
//If the length of string is 3 or less, only insertion is needed;
//If the length is 4, two insertions and might one replacement are needed;
//if the length is 5, one insertion and might two replacements are needed.
//So it's easy to solve for the case that length is less than 6: Math.Max(requiredChar, 6 - s.Length); The requiredChar is at most 3.
//
//For the case, 6<=length<=20, only replacements are needed.
//
//If length is greater than 20, only replacements and deletions are needed.
//For the case of a repeated substring which length is mutiple of 3 (note 3n, e.g. "aaa"), then one deletion will save a replacement to fix it;
//For the case of a repeated substring which length is mutiple of 3 plus 1 (note 3n+1, e.g. "aaaa"), then two deletions will save a replacement to fix it;
//For the case of a repeated substring which length is mutiple of 3 plus 2 (note 3n+2, e.g. "aaaaa"), then three deletions will save a replacement to fix it;
//
//That is.
//
//public int StrongPasswordChecker(string s)
//{
//    int requiredChar = GetRequiredChar(s);
//    if (s.Length < 6) return Math.Max(requiredChar, 6 - s.Length);
//
//    // only need replacement and deletion now when s.Length >= 6
//    int replace = 0; // total replacements for repeated chars. e.g. "aaa" needs 1 replacement to fix
//    int oned = 0; // total deletions for 3n repeated chars. e.g. "aaa" needs 1 deletion to fix
//    int twod = 0; // total deletions for 3n+1 repeated chars. e.g. "aaaa" needs 2 deletions to fix.
//
//    for (int i = 0; i < s.Length;)
//    {
//        int len = 1; // repeated len
//        while (i + len < s.Length && s[i + len] == s[i + len - 1]) len++;
//        if (len >= 3)
//        {
//            replace += len / 3;
//            if (len % 3 == 0) oned += 1;
//            if (len % 3 == 1) twod += 2;
//        }
//        i += len;
//    }
//
//    // no need deletion when s.Length <= 20
//    if (s.Length <= 20) return Math.Max(requiredChar, replace);
//
//    int deleteCount = s.Length - 20;
//
//    // deleting 1 char in (3n) repeated chars will save one replacement
//    replace -= Math.Min(deleteCount, oned);
//
//    // deleting 2 chars in (3n+1) repeated chars will save one replacement
//    replace -= Math.Min(Math.Max(deleteCount - oned, 0), twod) / 2;
//
//    // deleting 3 chars in (3n+2) repeated chars will save one replacement
//    replace -= Math.Max(deleteCount - oned - twod, 0) / 3;
//
//    return deleteCount + Math.Max(requiredChar, replace);
//}
//
//int GetRequiredChar(string s)
//{
//    int lowercase = 1, uppercase = 1, digit = 1;
//    foreach (var c in s)
//    {
//        if (char.IsLower(c)) lowercase = 0;
//        else if (char.IsUpper(c)) uppercase = 0;
//        else if (char.IsDigit(c)) digit = 0;
//    }
//
//    return lowercase + uppercase + digit;
//}
//Any questions?