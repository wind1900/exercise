class Solution {
public:
	string minWindow(string S, string T) {
		unordered_map<char, int> m;
		int i, j, z;
		string r;
		for (i = 0; i < T.size(); i++) {
		    if (m.count(T[i]) == 0) m[T[i]] = -1;
			else m[T[i]]--;
		}
		z = m.size();
		for (i = 0; i < S.size() && m.count(S[i]) == 0; i++);
		m[S[i]]++;
		if (m[S[i]] == 0) z--;
		for (j = i + 1; j < S.size() && z > 0; j++) {
			if (m.count(S[j]) > 0) {
				m[S[j]]++;
				if (m[S[j]] == 0) {
					z--;
				}
			}
		}
		if (z == 0) r = S.substr(i, j - i);
		else return "";
		while (i < S.size()) {
			m[S[i]]--;
			if (m[S[i]] == -1) z++;
			i++;
			while (i < S.size() && m.count(S[i]) == 0) i++;
			for (; j < S.size() && z > 0; j++) {
				if (m.count(S[j]) > 0) {
					m[S[j]]++;
					if (m[S[j]] == 0) {
						z--;
					}
				}
			}
			if (z == 0) {
				if (j - i < r.size())
					r = S.substr(i, j - i);
			}
			else break;
		}
		return r;
	}
};
