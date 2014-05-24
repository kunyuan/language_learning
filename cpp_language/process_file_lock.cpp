/* This is a test code to demonstrate that when a process writes to a file , it will
 * automatically get a file lock. So multiprocesses could write to the same file at
 * the same time without mass it up! */
#include <unistd.h>
#include <stdio.h>
#include <fstream>
int main()
{
    for (int i = 0; i < 5; i++ )
    {
        //sleep(1);
        if (fork() == 0)
        {
            //Way 1
            //printf("%d", getpid());
            //FILE *f=fopen("test.dat","a");
            //for (int j=0;j<10;j++)
            //{
            //fprintf(f,"log %d: %d\n",getpid(),j);
            //}
            //fclose(f);
            //
            //Way 2
            //std::ofstream file;
            //file.open("test.dat", std::ios::app);
            //
            //Way 3
            std::fstream file;
            file.open("test.dat", std::ios::app|std::ios::out);
            for (int j=0; j<10; j++)
            {
                file<<"log"<<getpid()<<":"<<j<<std::endl;
            }
            file.close();
        }
        else
        {
            return 0;
        }
    }
}
