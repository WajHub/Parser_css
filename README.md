# CSS Engine

This project aims to develop a simple CSS processing engine. It reads CSS sections interleaved with command sections from the standard input, parses the CSS sections, and organizes them in appropriate data structures. The command sections are also parsed and executed, with the results printed to the standard output (if applicable).
The goal of the project is to learn the basic tools included in the STL (e.g. string, list). The "Tests" folder contains sample inputs and outputs.

## CSS Processing

The processing starts by reading CSS declarations. CSS is syntactically correct and consists of attribute blocks optionally preceded by selectors. Lack of selectors is valid and indicates attributes applied to everything.

- Selectors are separated by commas. Legal CSS selectors can be used, assuming they don't contain commas or curly braces.
- Attribute blocks are enclosed in curly braces.
- Attributes are separated by semicolons and consist of a name (property) and a value separated by a colon. The last attribute in a block may or may not end with a semicolon.
- Attribute values can contain legal CSS constructs, but for simplicity, it can be assumed that strings are not malicious, i.e., they don't contain escaped quotation marks, curly braces, or semicolons.
- If a specific attribute (name) appears multiple times in a block, it should be treated as a single occurrence, with the last value being significant.
- Selectors, attribute names, and attribute values don't require semantic interpretation. They are treated as values after removing leading and trailing white spaces. For example, 'margin-left: 8px', 'margin: 4px 7px 4px 7px' are treated as separate, unrelated attributes with names 'margin-left' and 'margin' and values '8px' and '4px 7px 4px 7px', respectively. Similarly, selectors are treated as values and don't require interpretation, e.g., 'h1' and 'h1.theme' are treated as separate, unrelated selectors.
- Simplification: CSS does not contain comments or @-type selectors, and blocks cannot be nested.
- For the purpose of most tests (without significant loss), it can be assumed that no selector or attribute spans multiple lines (multiple separators or attributes can appear on a single line).

## Commands

In the following commands, i, j, and n are positive integers (fitting within an int data type), while S and A are legal attribute names.

- "????" - Start of a command section.
- "****" - Resume reading CSS.
- "?" - Print the number of CSS blocks.
- "i,S,?" - Print the number of selectors for the i-th block (numbering starts from 1). Skip if the block doesn't exist.
- "i,A,?" - Print the number of attributes for the i-th block. Skip if the block or attribute doesn't exist.
- "i,S,j" - Print the j-th selector for the i-th block (numbering starts from 1). Skip if the block or selector doesn't exist.
- "i,A,n" - Print the value of attribute n for the i-th block. Skip if it doesn't exist.
- "n,A,?" - Print the total number of occurrences of attribute n across all blocks. Possible result: 0.
- "z,S,?" - Print the total number of occurrences of selector z across all blocks. Possible result: 0.
- "z,E,n" - Print the value of attribute n for block z, considering multiple occurrences of selector z. Take the last occurrence. Skip if it doesn't exist.
- "i,D,*" - Delete the entire i-th block (separators + attributes). After successful execution, print "deleted".
- "i,D,n" - Delete attribute n from the i-th block. If the operation results in an empty block, it should

also be deleted (along with any selectors). After successful execution, print "deleted".

## Implementation Notes

Selectors and attributes should be stored as lists.
Individual CSS blocks should be stored in a doubly linked list (to efficiently handle command E - last attribute occurrence). To better utilize memory, the list should include an array T=8 of structures representing a block (where T is a compile-time constant) and a counter for currently occupied structures (to handle potential deletions). Counters should be utilized to speed up operations that take cell numbers as parameters (e.g., i).

When allocating a new node, a T-element array should be created. When adding elements, if there is free space in the list node, it should be utilized before allocating new nodes. If an array becomes empty as a result of deleting elements, the node should be removed. There's no need to move elements between nodes or merge nodes.

Example:

Input:
```
#breadcrumb
{
width: 80%;
font-size: 9pt;
}
h1, body {
min-width: 780px;
margin: 0;
padding: 0;
font-family: "Trebuchet MS", "Lucida Grande", Arial;
font-size: 85%;
color: #666666;
}
h1, h2, h3, h4, h5, h6 {color: #0066CB;}
????
?
1,S,?
1,S,1
1,A,?
2,A,font-family
h1,S,?
color,A,?
h1,E,color
1,A,padding
1,D,*
?
2,D,color
?
****
h1, h2, h3, h4, h5, h6 {color: #0066FF;}
????
?
```

Output:
```
? == 3
1,S,? == 1
1,S,1 == #breadcrumb
1,A,? == 2
2,A,font-family == "Trebuchet MS", "Lucida Grande", Arial
h1,S,? == 2
color,A,? == 2
h1,E,color == #0066CB
1,D,* == deleted
? == 2
2,D,color == deleted
? == 1
? == 2
```
