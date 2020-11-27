<?php
/**
 *
 */
class Book_model extends CI_model
{
  function get_book($id){
    $this->db->select('*');
    $this->db->from('Kortti');
    if($id !== NULL) {
      $this->db->where('Korttinumero',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_book($add_data){
    $this->db->insert('Kortti',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  function update_book($id, $update_data){
    $this->db->where('Korttinumero',$id);
    $this->db->update('Korttinumero',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }

  function delete_book($id){
    $this->db->where('Korttinumero',$id);
    $this->db->delete('Korttinumero');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}