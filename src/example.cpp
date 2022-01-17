#include "topic_transcriber.hpp"
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>

namespace {

std_msgs::String process(std_msgs::Int32 const & in) {
    std_msgs::String out;
    // Do any stateless processing here
    out.data = std::to_string(in.data);
    return out;
}

}


int main(int argc, char * * argv) {

    ros::init(argc, argv, "topic_converter_example");

    TopicTranscriber converter("in", "out", process);

    ros::spin();

    return 0;
}
