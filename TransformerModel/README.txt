  Creators: Parker Spaan and Matthew Powers
  Date: 4/25/2023

  
=== Description ===
This program is a python jupyter notebook that is able to take in any sentance or paragraphs and 
return the setiment of the sentance based on the training data as well as the BERT transformer. 

As mentioned this utilizes BERT to figure out the conjuntions and relationships of each word in the 
training set. With this it will then utilize the labels of the training data sentances to give an
output of what the setiment of the sentance was. 

This will first run on the CPU of the computer, then utilizing CUDA will run on the GPU for running 
test set and finding the accuracy of the model (it is around 78% depending on what seed is used). 
1 – (Number of misclassified samples / Total number of samples) is utilized to find this accuracy


=== Sentiment a phrase can be: ===

admiration
amusement
anger
annoyance
approval
caring
confusion
curiosity
desire
disapointment
disapproval
disgust
embarrassment
excitement
fear
gratitude
grief
happiness
joy
love
nervousness
optimism
pride
realization
relief
remorse
sadness
surprise

