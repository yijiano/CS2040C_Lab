#include "queue_simulator.h"

vector<Customer> QueueSimulator::simulateQueue(const vector<Customer>& customers) {
    if (customers.size() == 0) throw std::out_of_range("No customers");
    
    vector<Customer> final_queue;
    Heap<Customer> queue;
    vector<Customer> buffer;
    vector<int> server_times(_num_servers, 0);

    // Init queue based on priority order
    for (size_t i = 0; i < customers.size(); i++) {
        customers[i].set_compare_by_processing_time(_priority_order);
        queue.insert(customers[i]);
    }

    // Main loop to serve customer
    while (final_queue.size() != customers.size()) {

        // Find the server with the minimum service time 
        int min_time_server = 0;
        for (int i = 0; i < _num_servers; i++) {
            if (server_times[i] < server_times[min_time_server]) min_time_server = i;
        }

        // Find next customer to queue
        bool found_customer = false;
        while (!queue.empty() && !found_customer) {
            Customer current_customer = queue.extractMax();
            // Check if current server is available
            if (current_customer.arrival_time() <= server_times[min_time_server]) {
                found_customer = true;
                current_customer.set_service_time(server_times[min_time_server]);  
                server_times[min_time_server] = current_customer.service_time() + current_customer.processing_time();
                final_queue.push_back(current_customer);
            }
            else buffer.push_back(current_customer); //add current customer to buffer
        }

        // Increment time if customer not found
        if (!found_customer) server_times[min_time_server]++;

        // add buffer back to the queue, and clear buffer
        while(!buffer.empty()) {
            queue.insert(buffer.back());
            buffer.pop_back();
        }
    }
    return final_queue;
}