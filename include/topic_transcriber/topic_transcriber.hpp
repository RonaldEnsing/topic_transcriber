#pragma once
#include <ros/ros.h>
#include <string>

/// ROS Msg data type agnostic topic subscribe-process-and-publish node for stateless data processing pipelines
template <class In, class Out>
class TopicTranscriber{
    public:
        TopicTranscriber(
                std::string const & subscribe_topic,
                std::string const & publication_topic,
                Out (*process)(In)
                ) :
            process_(process)
    {
        publisher_   = nh_.advertise<Out>(publication_topic, 1);
        subscriber_  = nh_.subscribe(subscribe_topic, 1, &TopicTranscriber::callback, this);
    }

    private:
        ros::NodeHandle nh_;
        ros::Publisher publisher_;
        ros::Subscriber subscriber_;
        std::function<Out (In)> process_;

        void callback(In const & in) {
            publisher_.publish(process_(in));
        }
};
