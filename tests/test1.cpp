const char c = 'c';
const int MAX_N = 123456, MIN_N = -12345777, ZERO = 0;
const char C = 'C', space = ' ';

char underscore = '_';
int dp[MAX_N];
int ans;
int precomputed;
int has_error;
char number_char = '1';

void no_statement(int i, int j) {
    const char S = 'S';
    
    int n;
}

void dummy_test() {
    const char C = 'A';
    const int n1 = 1;
    
    int c_int, i;
    char ch, chs[10];
    int j;
    
    i = +0;
    j = +i + 5;
    j = -i - j;
    i = i / 1;
    j = -1 * j;
    i = -0;
    
    ;;
    { ; }
    { ;
        {{ ; }}
    }
    {}
    
    do i = i + 1;
    while (i < j)
    
    do {
        i = i - 1;
        j = j + 1;
    } while (i > j)
    
    for (i = j; i >= 0; i = i - 1) {}
    
    no_statement(i, j);
    
    scanf(i, j);
    printf(i + j);
}

void error(int n) {
    printf("Error: the input number n is too large! n: ", n);
    printf("n should be less than ", MAX_N);
    has_error = 1;
}

int fibonacci_recursive(int n) {
    if (n <= 0) {
        return (0);
    }
    if (n == 1) {
        return (1);
    }
    if (n > MAX_N) {
        error(n);
        return (-1);
    }
    return (fibonacci_recursive(n - 2) + fibonacci_recursive(n - 1));
}

void precompute() {
    int i;
    
    dp[0] = 0;
    dp[1] = 1;
    for (i = 2; i < MAX_N; i = i + 1) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    precomputed = 1;
}

int fibonacci_dp(int n) {
    if (n <= 0) {
        return (0);
    }
    if (n > MAX_N) {
        error(n);
        return (-1);
    }
    
    if (precomputed == 0) {
        precompute();
    }
    return (dp[n]);
}

void main() {
    int n_tests, i, n, ans_rec, ans_dp;
    
    dummy_test();
    precompute();
    scanf(n_tests);
    for (i = 0; i < n_tests; i = i + 1) {
        printf("Input a number n: ");
        scanf(n);
        has_error = 0;
        ans_rec = fibonacci_recursive(n);
        ans_dp = fibonacci_dp(n);
        if (has_error == 0) {
            if (ans_rec != ans_dp) {
                printf("One of the fib function is buggy on input ", n);
            } else {
                printf("fib(", n);
                printf(") = ", ans_rec);
            }
        }
    }
}
