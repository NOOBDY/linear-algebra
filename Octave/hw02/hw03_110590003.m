A = [1  4 0 2 -1;
     3 12 1 5  5;
     2  8 1 3  2;
     5 20 2 8  8]

X = [1  5 1 0 3;
     4 22 2 1 0;
     3 13 1 1 1;
     7 36 3 2 0]

C = [4 3;
     1 2]

function n = print_eq(A, B)
    if (isequal(A, B)) disp("YES") else disp("NO") end
end

% 1
disp("\n====== 1 ======\n");

r_A = rank(A)
r_AT = rank(A')

r_X = rank(X)
r_XT = rank(X')

r_C = rank(C);
r_CT = rank(C');

n_A = size(null(A), 2)
n_AT = size(null(A'), 2)

n_X = size(null(X), 2)
n_XT = size(null(X'), 2)

n_C = size(null(C), 2);
n_CT = size(null(C'), 2);

% 2
disp("\n====== 2 ======\n");

printf("rank(A) == rank(A^T): ");
print_eq(r_A, r_AT);
printf("rank(X) == rank(X^T): ");
print_eq(r_X, r_XT);
printf("rank(C) == rank(C^T): ");
print_eq(r_C, r_CT);

printf("dim(nul(A)) == dim(nul(A^T)): ");
print_eq(n_A, n_AT);
printf("dim(nul(X)) == dim(nul(X^T)): ");
print_eq(n_X, n_XT);
printf("dim(nul(C)) == dim(nul(C^T)): ");
print_eq(n_C, n_CT);

% 3
disp("\n====== 3 ======\n");

function colspace_M = colspace(M)
    colspace_M = [];
    counter = 1;
    rref_M = rref(M);

    for c = 1:size(M, 2)
        if (rref_M(counter, c) != 0)
            colspace_M(:, counter) = M(:, c);
            counter = counter + 1;
        end
    end
end

function rowspace_M = rowspace(M)
    rowspace_M = [];
    rref_M = rref(M);

    for r = 1:size(M, 1)
        if (any(rref_M(r, :)))
            rowspace_M(:, r) = (rref_M(r, :));
        end
    end
end

% A
% nul(A)
nul_A = null(A)

% col(A)
col_A = colspace(A)

% row(A)
row_A = rowspace(A)

% X
% nul(X)
nul_X = null(X)

% col(X)
col_X = colspace(X)

% row(X)
row_X = rowspace(X)

% 4
disp("\n====== 4 ======\n");

c = rref([col_A, col_X]);

printf("rank(A) == rank(X): ");
print_eq(r_A, r_X);

printf("col(A) == col(X): ");
print_eq(size(null(c), 2), size(colspace(c), 2));

% 5
disp("\n====== 5 ======\n");

c = rref([nul_A nul_X]);

printf("dim(nul(A)) == dim(nul(X)): ");
print_eq(n_A, n_X);

printf("nul(A) == nul(X): ");
print_eq(size(null(c), 2), size(colspace(c), 2));

% 6
disp("\n====== 6 ======\n");

[V, D] = eig(C)
