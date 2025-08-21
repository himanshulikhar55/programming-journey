package main

import "fmt"

func countSquares(matrix [][]int) int {
	ans := 0
	dp := make([][]int, len(matrix))
	for i := range dp {
		dp[i] = make([]int, len(matrix[0]))
	}
	for i := 0; i < len(matrix); i++ {
		dp[i][0] = matrix[i][0]
	}
	for j := 0; j < len(matrix[0]); j++ {
		dp[0][j] = matrix[0][j]
	}
	for i := 1; i < len(matrix); i++ {
		for j := 1; j < len(matrix[0]); j++ {
			if matrix[i][j] == 1 {
				dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))
			}
		}
	}
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			ans += dp[i][j]
		}
	}
	return ans
}

func main() {
	var m, n int
	fmt.Scanf("%d %d", &m, &n)
	matrix := make([][]int, m)
	for i := 0; i < m; i++ {
		matrix[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &matrix[i][j])
		}
	}
	fmt.Println(countSquares(matrix))
}
