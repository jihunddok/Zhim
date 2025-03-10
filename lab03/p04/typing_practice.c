/**
 * typing_test.c
 * author shimjihun
 * since 2019.11.11
 * check type speed and error rate
 */
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void result(int time1, int time2, char text1[], char text2[], char text3[], int total_error)
{
    int time_tmp;
    float typing_speed;

    time_tmp = time2 - time1;
    printf("time : %d sec(초)\n", time_tmp);

    // type spped  = (whole type - errored type ) / typing time * 60
    typing_speed = (((strlen(text1) + strlen(text2) + strlen(text3)) - total_error) / time_tmp) * 60;
    printf("type speed per minute : %.lf \n", typing_speed);
}

int main()
{
    int first_word_descriptor, second_word_descriptor, third_word_descriptor;
    int first_word_read, first_word_count = 0, first_word_error = 0;
    int second_word_read, second_word_count = 0, second_word_error = 0;
    int third_word_read, third_word_count = 0, third_word_error = 0;
    
    int total_error = 0;

    char first_word, first_word_text[] = "I'm tired because of lab03 report";
    char second_word, second_word_text[] = "System programming report";
    char third_word, third_word_text[] = "my name is shimijhun";

    struct termios init_attr, new_attr;
    time_t time1, time2;

    first_word_descriptor = open(ttyname(fileno(stdin)), O_RDWR);

    tcgetattr(first_word_descriptor, &init_attr);
    new_attr = init_attr;
    new_attr.c_lflag &= ICANON;
    new_attr.c_lflag &= ~ECHO;
    new_attr.c_cc[VMIN] = 1;
    new_attr.c_cc[VTIME] = 0;

    if (tcsetattr(first_word_descriptor, TCSANOW, &init_attr) != 0)
    {
        fprintf(stderr, "terminall err : can't set treminal preferences.\n");
    }

    printf("check typing rate.\n\n");

    time(&time1);

    printf("type this line.\n\n%s\n", first_word_text);
    while ((first_word_read = read(first_word_descriptor, &first_word, 1)) > 0 && first_word != '\n')
    {
        if (first_word == first_word_text[first_word_count++])
        {
            write(first_word_descriptor, &first_word, 1);
        }
        else
        {
            write(first_word_descriptor, "*", 1);
            first_word_error++;    
        }
    }

    tcsetattr(first_word_descriptor, TCSANOW, &init_attr);
    close(first_word_descriptor);

    second_word_descriptor = open(ttyname(fileno(stdin)), O_RDWR);

    tcgetattr(second_word_descriptor, &init_attr);
    new_attr = init_attr;
    new_attr.c_lflag &= ICANON;
    new_attr.c_lflag &= ~ECHO;
    new_attr.c_cc[VMIN] = 1;
    new_attr.c_cc[VTIME] = 0;

    if (tcsetattr(second_word_descriptor, TCSANOW, &init_attr) != 0)
    {
        fprintf(stderr, "terminal err : can't set terminal preferences.\n");
    }

    printf("\n\n%s\n", second_word_text);
    while ((second_word_read = read(second_word_descriptor, &second_word, 1)) > 0 && second_word != '\n')
    {
        if (second_word == second_word_text[second_word_count++])
        {
            write(second_word_descriptor, &second_word, 1);
        }
        else
        {
            write(second_word_descriptor, "*", 1);
            second_word_error++;    
        }
    }

    tcsetattr(second_word_descriptor, TCSANOW, &init_attr);
    close(second_word_descriptor);

    third_word_descriptor = open(ttyname(fileno(stdin)), O_RDWR);
    tcgetattr(third_word_descriptor, &init_attr);
    new_attr = init_attr;
    new_attr.c_lflag &= ICANON;
    new_attr.c_lflag &= ~ECHO;
    new_attr.c_cc[VMIN] = 1;
    new_attr.c_cc[VTIME] = 0;

    if (tcsetattr(third_word_descriptor, TCSANOW, &init_attr) != 0)
    {
        fprintf(stderr, "terminal err : can't set terminal preferences.\n");
    }

    printf("\n\n%s\n", third_word_text);
    while ((third_word_read = read(third_word_descriptor, &third_word, 1)) > 0 && third_word != '\n')
    {
        if (third_word == third_word_text[third_word_count++])
        {
            write(third_word_descriptor, &third_word, 1);
        }
        else
        {
            write(third_word_descriptor, "*", 1);
            third_word_error++;   
        }
    }

    tcsetattr(third_word_descriptor, TCSANOW, &init_attr);
    close(third_word_descriptor);

    total_error = first_word_error + second_word_error + third_word_error;
    printf("\n\n type err :  %d\n", total_error);
    time(&time2);
    result(time1, time2, first_word_text, second_word_text, third_word_text, total_error);

    return 0;
}
