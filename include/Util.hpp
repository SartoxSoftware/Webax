//
// Created by anerruption on 10/1/21.
//

#ifndef WEBAX_UTIL_HPP
#define WEBAX_UTIL_HPP

#include <cstdlib>
#include <cstring>

class Util
{
public:
    static char** Split(const char* chr, char* delim)
    {
        size_t buffers = 20, chars = 1024;

        char** result = (char**)malloc(buffers * sizeof(char*));
        size_t start = 0, i = 0;

        loop:

        char* buf = (char*)malloc(chars * sizeof(char*));
        size_t index = 0;

        for (; start < strlen(chr); start++)
        {
            char c = chr[start];

            bool isdelim = true;
            size_t len = strlen(delim);

            for (size_t tmp = 0; tmp < len; tmp++)
                if (chr[start + tmp] != delim[tmp])
                {
                    isdelim = false;
                    break;
                }

            if (isdelim)
            {
                buf[index] = '\0';
                result[i++] = buf;

                start += len;

                goto loop;
            } else buf[index++] = c;
        }

        buf[index] = '\0';
        result[i] = buf;

        return result;
    }
};

#endif //WEBAX_UTIL_HPP
