<?php

defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */
require APPPATH . 'libraries/REST_Controller.php';

/**
 * This is an example of a RestApi based on PHP and CodeIgniter 3.
 * 
 *
 * @package         CodeIgniter
 * @subpackage      Rest Server
 * @category        Controller
 * @Pvm          Pekka Alaluukas (edited the version made by Phil Sturgeon & Chris Kacerguis)
 * @license         MIT
 * @link            https://github.com/chriskacerguis/codeigniter-restserver
 */
class Book extends REST_Controller {

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Book_model');
    }

    public function book_get()
    {
        // book from a data store e.g. database  

        $id = $this->get('id');

        // If the id parameter doesn't exist return all books
        if ($id === NULL)
        {
            $book=$this->Book_model->get_book(NULL);
            // Check if the book data store contains book (in case the database result returns NULL)
            if ($book)
            {
                // Set the response and exit
                $this->response($book, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No action were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

         // Find and return a single record for a particular book.
        else {
            // Validate the id.
            if ($id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the book from the database, using the id as key for retrieval.
            $book=$this->Book_model->get_book($id);
            if (!empty($book))
            {
                $this->set_response($book, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'action could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

    }

    public function book_post()
    {
        // Add a new book
        $add_data=array(
          'idTili'=>$this->post('idTili'),
          'Tilinumero'=>$this->post('Tilinumero'),
          'Haltija'=>$this->post('Haltija'),
          'Saldo'=>$this->post('Saldo'),
          'idTapahtuma'=>$this->post('idTapahtuma')
        );
        $insert_id=$this->Book_model->add_book($add_data);
        if($insert_id)
        {
            $message = [
                'id_book' => $insert_id,
                'idTili' => $this->post('idTili'),
                'Tilinumero' => $this->post('Tilinumero'),
                'Haltija' => $this->post('Haltija'),
                'Saldo' => $this->post('Saldo'),
                'idTapahtuma'=>$this->post('idTapahtuma'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }

    }
    public function book_put()
    {
        // Update the book
        $id=$this->get('id');
        $update_data=array(
          'idTili'=>$this->put('idTili'),
          'Tilinumero'=>$this->put('Tilinumero'),
          'Haltija'=>$this->put('Haltija'),
          'Saldo'=>$this->put('Saldo'),
          'idTapahtuma'=>$this->put('idTapahtuma')
        );
        $result=$this->Book_model->update_book($id, $update_data);

        if($result)
        {
            $message = [
                'id_book' => $id,
                'idTili' => $this->put('idTili'),
                'Tilinumero'=>$this->put('Tilinumero'),
                'Haltija'=>$this->put('Haltija'),
                'Saldo'=>$this->put('Saldo'),
                'idTapahtuma'=>$this->put('idTapahtuma'),
                'message' => 'Updates a resource'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else 
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }

    public function book_delete()
    {
        $id = $this->get('id');

        // Validate the id.
        if ($id <= 0)
        {
            // Set the response and exit
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
        }
        $result=$this->Book_model->delete_book($id);
        if ($result)
        {
          $message = [
              'id_book' => $id,
              'message' => 'Deleted the resource'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete data'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }



}