#!/usr/bin/perl

#   Date: 17/02/2022
#   Authors :Andres C. Lopez R.,Oscar J. Reyes T., Luis F. Velasquez P.
#   Subjebt: Paralell Computation.
#   Topic: Design of experiments, 
#   automation of execution (average and deviation).

$PATH = `pwd`;
chomp($PATH);
print("Source: ".$PATH. "\n\n");

#Varaible who represents the number of repetitions for each executable file   
$N = 31;
#Vector of executable benchmarks
@ejecutables = ("exeBenchC", "exeBenchCPP","exeBenchCPP_reference");

#Vector NxN for matrix
@matrix_size = ("100", "300", "600", "1000","2000");

foreach $exe (@ejecutables){
    foreach $size (@matrix_size){
        $file = "$PATH/"."registros/"."$exe"."-$size".".txt";
        #print($file."\n");
        for ($i = 0; $i < $N; $i++){
            #print("$PATH/$exe $size \n");
            system "$PATH/$exe $size >> $file";
        }
        close $file; 
    }
}
exit(0);

# To make this file executable
#   chmod +x launcher.pl
