% (a)
A = [2 -2;
     3 -5];

B = [-2 0;
      4 2];

C = [-1 2 0;
      2 0 3];

E = [ 2       -1;
     pi log10(2);
     -2        3];

F = [1 2 3;
     2 3 4;
     3 5 7];

I = eye(3);

% (b)
A(2, 1)

E(3, 1)

C(2, :)

% (c)
A + 2 * B

C - B * E.'

A.'

% (d)
M = A * B
N = B * A

if (isequal(A, B))
    disp("YES")
else
    disp("NO")
end

% (e)
P = C.' * B.'
Q = (B * C).'

if (isequal(P, Q))
    disp("YES")
else
    disp("NO")
end

% (f)
if (det(A) == 0)
    disp("Not invertible")
else
    inv(A)
end

if (det(F) == 0)
    disp("Not invertible")
else
    inv(F)
end
