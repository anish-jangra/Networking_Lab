#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		printf("Error making Process!\n");
		return (-1);
	}
	if (pid == 0) // if child process is running
	{
		printf("Child Process\nHey I am child\n");
		sleep(1);
	}
	if (pid > 0)
	{
		printf("Parent\nPID of child : %d and PID of parent : %d\n", getpid(), getppid());
		sleep(1);
		return (0);
	}
}