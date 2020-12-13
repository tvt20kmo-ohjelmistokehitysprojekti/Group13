<?php

defined('BASEPATH') OR exit('No direct script access allowed');
require APPPATH . 'libraries/REST_Controller.php';

class Balance extends REST_Controller {
    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Balance_model');
    }

    public function Balance_post(){
        
        $card_id=$this->post('idcard');
        $result=$this->Balance_model->get_balance($card_id);

        echo json_encode($result);
    }
}