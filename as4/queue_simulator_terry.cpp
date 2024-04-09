#include "queue_simulator.h"
#include "heap_queue_simulator.h"
/* -------------------------------------------------------------------------------------------------------------------------- */
vector<Customer> QueueSimulator::simulateQueue(
    const vector<Customer> &customers)
{
    // Done: Implement this function.

    /* --- Create Time Queue  -------------------------------------------------- */
    int end_time = 0;
    int size = customers.size();
    int max_arrival_timing = -1; 
    
    // Convert Max Heap into Min Heap
    for (int i = 0; i < customers.size(); i++)
    {
        max_arrival_timing = max(max_arrival_timing, customers[i].arrival_time());
    }
    
    /* --- Create Priority Queue  -------------------------------------------------- */
    Heap<Customer> heap_priority = Heap<Customer>();
    for (int i = 0; i < customers.size(); i++) // Convert to Array
    {
        Customer c = customers[i];
        c.set_compare_by_processing_time(_priority_order);
        heap_priority.insert(c);
    }

    /* --- Queue  -------------------------------------------------- */
    vector<Customer> customers_serve_order;

    Customer *temp_store = new Customer[size];
    int temp_store_len = 0; // Empty

    int *cumulative_service_times = new int[_num_servers];
    for (int i=0; i<_num_servers; i++){
        cumulative_service_times[i] = 0;
    }

    // Loop for Timing - Find the min timing first
    while (customers_serve_order.size() < size) { // not all queued out
    
        int curr_server = 0;
        for (int i=curr_server; i<_num_servers; i++){
            if (cumulative_service_times[i] < cumulative_service_times[curr_server]){
                curr_server = i;
            }
        }

        // Find next customer to queue
        bool found = false;
        while (!heap_priority.empty() && !found) {
            Customer customer = heap_priority.extractMax();
            // Check if current server is available
            if (customer.arrival_time() <= cumulative_service_times[curr_server]){
                customer.set_service_time(cumulative_service_times[curr_server]);  
                customers_serve_order.push_back(customer);
                cumulative_service_times[curr_server] = customer.service_time() + customer.processing_time();
                found = true;
            } else {
                temp_store[temp_store_len] = customer;
                temp_store_len++;
            }
        }
        if (!found) {
            cumulative_service_times[curr_server]++; // Move if there's nothing
        }
        for (int i=0; i<temp_store_len; i++) {
            heap_priority.insert(temp_store[i]);
        }
        temp_store_len = 0; // clear store
    }
    delete[] temp_store;
    delete[] cumulative_service_times;
    return customers_serve_order;
}