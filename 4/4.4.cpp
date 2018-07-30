// File: 4.4.cpp
// Author: iBug

Status StrInsert(HString &S, int pos, HString T) {
    if (pos < 1 || pos > S.length + 1)
        return ERROR;
    if (T.length) {
        if (!(S.ch = realloc(S.ch, (S.length + T.length) * sizeof(char))))
            return OVERFLOW;
        int i;
        for (i = S.length - 1; i >= pos - 1; --i)
            S.ch[i + T.length] = S.ch[i];
        for (i = 0; i < T.length; i++)
            S.ch[pos - 1 + i] = T.ch[i];
        S.length += T.length;
    }
    return OK;
}
