#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dir.h>

using namespace std;

long long size, count, fcount;

void dfs(){
    DIR* dp = opendir(".");
	struct dirent *res;

	while ((res = readdir(dp)) != NULL) {
        if(strcmp(res->d_name, ".")==0 || strcmp(res->d_name, "..")==0) continue;
        struct stat info;
    	stat(res->d_name, &info);
    	if(S_ISDIR(info.st_mode)){
            fcount++;
    	}else{
            size += info.st_size;
            count++;
    	}

	}
    closedir(dp);
}

int main()
{
	dfs();
	cout << count << " " << fcount<< " " << size;
    return 0;
}

