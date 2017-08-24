## WIP

The code is not yet available. This is due to instability and constant change of the code.

We are still exploring how to make **3Motion** better for those who will use it. When a stable version is reached we will make it public.

If you wish to have access to it please contact us.

# What is 3Motion?

This project allows the creation of agents and their behavior with the objective of creating more believable interactions.

This project is based on a thesis that defends that the subdivision of an action into several stages increases the immersion of the audience in a scene.

Links to the papers will be posted when available.
<!-- 
- [Towards Believable Interactions between Synthetic Characters]() - Poster paper describing the model (4 pages).
- [Measuring Believable Interactions, a Case Study: 3Motion]() - Workshop paper focusing on the User Study 
-->

# Contact Us!

If you want to know more about the project or want to get access to the code please contact us!

Ricardo Rodrigues - ricardo.proenca.rodrigues@tecnico.ulisboa.pt

Professor Carlos Martinho - carlos.martinho@tecnico.ulisboa.pt

# How does it work?

Our agent’s behavior is a 4-step *anticipation-based* cycle: (1) the agent *perceives* changes in the world based on its *expectations*, (2) *reacts* to them emotionally based on what is *anticipated*, (3) *decides* what to do next and *anticipates* what will happen, (4) and *performs* part of an on-going action, then repeats. This cycle occurs multiple times in the course of an action allowing the virtual agents to perceive events and express different emotions, among other things, while performing a same action that gives context to that expression.

**3Motion** differentiates itself from standard approaches in how it de-constructs the traditional atomic action generally used when implementing virtual agents behavior,into three explicit and distinct stages: *anticipation*, *action*, and *follow-through*. Each stage may take a certain time to play out, and interaction at different points in the sequence will have a different meaning for the other agents participating in the scene, as well as for the viewer passively watching or actively interacting with the scene, allowing for the creation of a richer interaction.

## Example of the Execution Flow

To better showcase the expressive potential of our approach, we present an example of its execution ﬂow. In our example, three agents take part in the action: Bob, Hanna and Steve. We join the action as Bob, currently in a happy mood, decides to throw a ball (decide step). In the perform step, the action is initiated: raising his arm in preparation for the throw, Bob enters the first stage of the expression of an action, *anticipation*.

![Execution Example](https://www.dropbox.com/s/i37wgqm18h4jdls/actionFlow.png?raw=1)

The *anticipation* stage serves the purpose of communicating the intent so every other agent understands it and can expressively prepare for it. In this stage, an agent broadcasts its intent and associated emotion, and receives feedback in the form of emotions from the other agents that are aware of the expression: 

    Bob is happy and wants to throw the ball, Hanna responds she is happy for Bob, while Steve is afraid Bob will miss his mark. 

This allows Bob to interpret the emotional reactions in the context of his intentions and modulate his behavior accordingly.

Anticipation is further subdivided into two sub-stages: an *interruptible* stage in which the agent is still able to cancel the initiated action, and an *uninterruptible* stage in which the action reached a point where it cannot be stopped.

    While Bob has the ball in his hand, he is able to cancel the throw. While Steve is fearful, Hanna is happy for him, so Bob decides to proceed with the throw. He releases the ball.

At this point Bob enters the uninterruptible stage, in which the action is still not finished and the agent can create an expectation about its outcome, which is later broadcast as an emotion and may provoke an affective response from the other agents.

    Bob is confident about his throw, which gets Hanna excited and Steve more at ease.

The precise timing of the expression and affective responses is crucial in this stage, otherwise, the audience may not be able to understand how decision-making took place in this shared affective context.

The *action* stage is instantaneous and only exists conceptually. This stage represents the moment the action is resolved and the state of the virtual world changes. In the example, this would occur when the ball hits the target.

The *follow-through* stage is entered after the action is resolved and the result of the action is broadcast, which will meet or challenge the expectations of the agents. As in the anticipation stage, the agent sends its affective appraisal to others along with the result, allowing them to feel happy, sorry, etc. and receives their affective feedback to perform a final appraisal of the action.

    Bob hits the target and is very happy! Hanna rejoices sharing on the happiness; Steve is now relieved because all went well. Their responses further increases Bob’s happiness. 

Since we focus on non-verbal communication, emotions play a very important role on the communication of the actions progression. With the use of emotions, we hope to improve the believability of the interaction without compromising other parallel forms of communication.

# Acknowledgements

 This work was partially supported by national funds through Fundacão para a Ciência e a Tecnologia (FCT) with ref. UID/CEC/50021/2013, and FCT grant from project Tutoria Virtual with ref. TDC/IVC-PEC/3963/2014.
