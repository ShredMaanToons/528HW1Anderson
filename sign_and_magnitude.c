void classifier();
void classifier_test(int num);

int main(void)
{
    classifier_test(-1);
    classifier_test(0);
    classifier_test(1);
    classifier_test(-234234);
    classifier_test(777);
    classifier();
}

void classifier()
{
    int num = 0;
    int abval = 0;
    printf("Input an integer: ");
    scanf("%d", &number);
    if(num > 0){
        printf("%d is a positive number ", num);
        abval = num;
    }
    else if(num < 0){
        printf("%d is a negative number ", num);
        abval = -num;
    }
    else{
        printf("%d is zero ", num);
    }
    printf("with absolute value: %d\n", abval);
}

void classifier_test(int num)
{
    int abval = 0;
    if(num > 0){
        printf("%d is a positive number ", num);
        abval = num;
    }
    else if(num < 0){
        printf("%d is a negative number ", num);
        abval = -num;
    }
    else{
        printf("%d is zero ", num);
    }
    printf("with absolute value: %d\n", abval);
}
