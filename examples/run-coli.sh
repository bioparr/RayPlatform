nohup /software/openmpi-1.5/bin/mpirun -np 22 ../Ray \
 -p /data/users/sra/SRA001125/sdata/SRR001665_1.fastq /data/users/sra/SRA001125/sdata/SRR001665_2.fastq \
 -p /data/users/sra/SRA001125/sdata/SRR001666_1.fastq /data/users/sra/SRA001125/sdata/SRR001666_2.fastq \
 -o ecoli.fasta > ecoli.log &
