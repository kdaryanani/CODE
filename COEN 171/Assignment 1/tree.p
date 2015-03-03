{Karan Daryanani, MWF 9:15-10:20, HW 1 tree in pascal}

program tree;

{Your program should accept input from standard input (e.g., the keyboard) in the following form: a series of  integers, terminated by -1 , to insert into a tree, followed a sequence of integers, again terminated by -1 , to check  for membership. The only output your program should produce when checking for membership is true if a given  integer is found in the tree and false if the integer is not found in the tree. All inputs and outputs will appear on  separate lines.}


{Creates the structure for the Binary Tree. ^ refers to a pointer essentially}
type
	BinaryTreePointer = ^BinaryTree;
	BinaryTree = record
		left: BinaryTreePointer;
		right: BinaryTreePointer;
		upperNODE: BinaryTreePointer;
		element: integer
end;


{Global Definitions}

var root : BinaryTreePointer;
var a, z, c, x,d   : integer; {Unused c}


{Proceude to initalize a tree from nil}

procedure init_new_root(var x: integer; tree : BinaryTreePointer);
begin
	tree^.left := nil;
	tree^.right := nil;
	tree^.upperNODE := nil;
	tree^.element := x
end;


{Procedue to see if an element is in the binary search tree. O(nlogn)}
procedure contains(var x: integer; upperNODE: BinaryTreePointer);

	begin
		if upperNODE^.element = x then begin
			writeln ('Your Element has been found ', x);
			Exit()
		end			
		else begin
			if upperNODE^.left <> NIL then
				contains(d, upperNODE^.left);
			if upperNODE^.right <> NIL then
				contains(d, upperNODE^.right);
		end;
	end;

{procedue to insert an element into the tree. If there is no tree, init_new_root is called to create an element. The follow procedures Place the element based on its value. }
procedure insert(var x: integer; upperNODE: BinaryTreePointer);
var NODE : BinaryTreePointer;

	begin
	new (NODE);
	init_new_root(x, NODE);

	if upperNODE^.element < x then
		if upperNODE^.left = NIL then begin
			upperNODE^.left := NODE;
			NODE^.upperNODE := upperNODE;
		end
		else 
			insert(d, upperNODE^.left);

	if upperNODE^.element > x then
		if upperNODE^.right = NIL then begin
			upperNODE^.right := NODE;
			NODE^.upperNODE := upperNODE;
		end
		else 
			insert(x, upperNODE^.right)
	end;

{Main to create a root and take in values}
begin

	new (root);

	z := 0;
	repeat
		read(a);
		if z = 0 then
			init_new_root(a, root)
		else
			insert(a, root);
		inc(z);
	until a = -1;

	repeat
		read(a);
		contains (a, root)
	until a = -1;
	
end.