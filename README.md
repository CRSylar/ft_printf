# ft_printf
reproducing the printf C function for a 42 project

My ft_printf version for the 42 school project, graded 102/100 by Moulinette
it reproduces che behavior of the type :  diuxXpsc ;
                              the flags:  -0*(for width & precision)

it also work with the bonus type : nf
and the bonus flags: + # (yes, the space is a flag)

I've got "only" 102 instead of 107 for a little error in the handle of n type
the float conversion works perfectly until the 15nt decimal position
there's some accuracy problem starting from the 16nt

Don't forget to take a look at my Libft repo, in there you'll find all the useful function that i've used
some of that is not included in the original Libft project and i write it for printf, but i decided to move in the
lib for future use.
