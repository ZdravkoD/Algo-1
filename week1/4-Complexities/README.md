# Complexities

Write down the asymptotic complexities of the following functions:

## Checking if a number is prime

```
is_prime(number) {
  for (i = 2; i < number; i++) {
    if (number % i == 0) {
      return false
    }
  }
  return true
}
```

Complexity: O(n)

## Checking if a string is palindrome

```
is_palindrome(string) {
  n = length(string)

  i = 0
  j = n - 1
  while (i < j) {
    if (string[i] != string[j]) {
      return false
    }
    i = i + 1
    j = j - 1
  }

  return true
}
```

Complexity: O(n)

## Summing elements of a matrix

```
for (i = 0; i < n; i++) {
  for (j = 0; j < m; j++) {
    sum += numbers[i][j]
  }
}
```

Complexity: O(n*n)

## Counting 1

```
for (i = 0; i < n; i++) {
  for (j = i; j < n; j++) {
    count++
  }
}
```

Complexity: O(n)

## Counting 2

```
for (i = 0; i < n; i++) {
  for (j = 1; j < n; j*=2) {
    count++
  }
}
```

Complexity: O(n*log(n))
