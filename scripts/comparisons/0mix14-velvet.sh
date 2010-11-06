source ../0mix11-parameters.sh
source ../0mix13-parameters.sh
source ../0parameters.sh
shuffleSequences_fastq.pl $p1left $p1right reads1.fastq
shuffleSequences_fastq.pl $p2left $p2right reads2.fastq
velveth velvet $wordSize -fastq -shortPaired reads1.fastq -shortPaired2 reads2.fastq  -long -fasta $r4541 $r4542 $r4543 
velvetg velvet   -ins_length $length1 -ins_length_sd $sd1 -ins_length2 $length2 -ins_length_sd $sd2  -exp_cov 109  -cov_cutoff 10
ln -s velvet/contigs.fa Assembly.fasta
ln -s $ref Reference.fasta
echo Velvet>Assembler.txt