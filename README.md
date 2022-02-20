# Single-Channel-Queue
In Single-Channel-Queuing Problem, one customer is served at a single time. If the server is busy then the customers have to wait in queue.  We have to solve single channel queuing problem in python. Firstly, we have to define inter arrival time by using Poisson distribution and Service time are define by using Exponential distribution. This problem is defined for 20 customers.  First inter arrival time, arrival time, Time service begin, customer wait in queue, idle time of server is defined as 0.  The value of second to twenty value are find by using this function:

## Team-Impossible members
-  👋 Hi, I’m [Yeasinul Alam](https://github.com/yeasinul)
-  👋 Hi, I’m [Mishan](https://github.com/1mishan1)
-  👋 Hi, I’m [Md. Naimur Rahman](https://github.com/naimur404)
-  👋 Hi, I’m [Hossain Mohamad Nayeem]()
-  👋 Hi, I’m [Shaheed Abdullah]()

The value of second to twenty value are find by using this function:
## What is Probability Distribution
- ***Probability distribution*** yields the possible outcomes for any ***random event***. It is also defined based on the underlying sample space as a set of possible outcomes of any random experiment. These settings could be a set of real numbers or a set of vectors or set of any entities. It is a part of probability and statistics. ***Poisson Distribution*** and ***Exponential Distribution*** are two types of Probability Distribution **among 7 types*** of probability distribuiton.

## Short introduction to Poisson Distribution
- ***Poisson random variable*** is typically used to model the number of times an event happened in a time interval. For example, the number of users visited on a website in an interval can be thought of a Poisson process. Poisson distribution is described in terms of the rate ***(μ)*** at which the events happen. An event can occur ***0, 1, 2, …*** times in an interval. The average number of events in an interval is designated ***λ (lambda)***. Lambda is the event rate, also called the ***rate parameter***. The probability of observing ***k*** events in an interval is given by the equation:<br/>
 ![image](https://user-images.githubusercontent.com/74718375/112758781-e2de5f00-9011-11eb-952d-a0859d50300e.png)<br/>

## Short introduction to Exponential Distribution
- ***The exponential*** distribution describes the time between events in a ***Poisson point*** process, i.e., a process in which events occur continuously and independently at a constant average rate. It has a parameter ***λ*** called ***rate parameter***, and its equation is described as :<br/>
 ![image](https://user-images.githubusercontent.com/74718375/112759206-d3601580-9013-11eb-909f-b215e2b6ca32.png)<br/>

## Why Poisson Distribution is used for Inter-Arrival Time
- Poison distribution usually works with a ***discrete*** value. Since inter-arrival time does not come in a sequential way, it comes in a random way, so poison distribution is used in this case

## Why Exponential Distribution is used for Service Time
- Exponential Distribution deals with the time between occurrences of successive events as time flows by
continuously. Here starting and ending of service can be considerred as two successive events.
