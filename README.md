# topic_transcriber

Implementing a ROS node that takes a single incoming topic, some stateless processing and a single outgoing topic?
Then consider the `topic_transcriber`.
Accepts any incoming and outgoing message types.
Hides the code duplication of setting up node handles, subscribers, publishers, etc.
