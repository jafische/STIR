//
// $Id$: $Date$
//
/*!

  \file
  \ingroup buildblock
  \brief inline implementations for class RelatedViewgrams

  \author Kris Thielemans
  \author PARAPET project

  \date $Date$

  \version $Revision$
*/
START_NAMESPACE_TOMO

template <typename elemT>
RelatedViewgrams<elemT>::RelatedViewgrams() :
     viewgrams(), symmetries_used()
     {}
  
template <typename elemT>
RelatedViewgrams<elemT>::RelatedViewgrams(const vector<Viewgram<elemT> >& viewgrams,
                   const shared_ptr<DataSymmetriesForViewSegmentNumbers>& symmetries_used)
		   : viewgrams(viewgrams), 
		     symmetries_used(symmetries_used)
  {
    check_state();
  }

template <typename elemT>
void RelatedViewgrams<elemT>::check_state() const
{
#ifndef NDEBUG
  debug_check_state();
#endif
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_num_viewgrams() const
{
  check_state();
  return viewgrams.size();
}


template <typename elemT>
int RelatedViewgrams<elemT>::get_basic_view_num() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_view_num();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_basic_segment_num() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_segment_num();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_num_axial_poss() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_num_axial_poss();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_num_tangential_poss() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_num_tangential_poss();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_min_axial_pos_num() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_min_axial_pos_num();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_max_axial_pos_num() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_max_axial_pos_num();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_min_tangential_pos_num() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_min_tangential_pos_num();
}

template <typename elemT>
int RelatedViewgrams<elemT>::get_max_tangential_pos_num() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_max_tangential_pos_num();
}

template <typename elemT>
const ProjDataInfo * RelatedViewgrams<elemT>::get_proj_data_info_ptr() const
{
  assert(viewgrams.size()>0);
  check_state();
  return viewgrams[0].get_proj_data_info_ptr();
}

#if 0
template <typename elemT>
const Viewgram<elemT>&  RelatedViewgrams<elemT>::get_viewgram_reference(const int n) const
{
  assert(viewgrams.size()>static_cast<unsigned>(n) && n>=0);
  check_state();
  return viewgrams[n];
}

// a non-const access
// Only the data itself should be modified.
// sizes and scan_info should remain identical
template <typename elemT>
Viewgram<elemT>&  RelatedViewgrams<elemT>::get_viewgram_reference(const int n)
{
  assert(viewgrams.size() > static_cast<unsigned>(n) && n>=0);
  check_state();
  return viewgrams[n];
}

#endif

template <typename elemT>
RelatedViewgrams<elemT>::iterator 
RelatedViewgrams<elemT>::begin()
{ return viewgrams.begin();}

template <typename elemT>
RelatedViewgrams<elemT>::iterator 
RelatedViewgrams<elemT>::end()
{return viewgrams.end();}

template <typename elemT>
RelatedViewgrams<elemT>::const_iterator 
RelatedViewgrams<elemT>::begin() const
{return viewgrams.begin();}

template <typename elemT>
RelatedViewgrams<elemT>::const_iterator 
RelatedViewgrams<elemT>::end() const
{return viewgrams.end();}


END_NAMESPACE_TOMO
