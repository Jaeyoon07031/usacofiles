def fast_exp(number, power):
    if (power == 0 or power == 1):
        return number;
    elif (power % 2 == 0):
        return fast_exp(number * number, power / 2);
    elif (power % 2 == 1):
        return number * fast_exp(number * number, (power - 1) / 2);

if __name__ == "__main__":
    n, p = input().split(' ');
    n = int(n);
    p = int(p);

    output = str(fast_exp(n, p));

    outputSpliced = [];
    for i in range(0, len(output), 70):
        outputSpliced.append(output[i : i + 70]);
    for i in range(0, len(outputSpliced)):
        print(outputSpliced[i]);