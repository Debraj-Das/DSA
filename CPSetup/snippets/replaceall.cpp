string replaceAll(string str, const string& from, const string& to) {
   if (from.empty() or from == to) {
      return str;
   }
   for (size_t i = 0; (i = str.find(from, i)) != string::npos;
        i += to.length()) {
      str.replace(i, from.length(), to);
   }
   return move(str);
}